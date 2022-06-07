<?php

/**
 	* Copyright (C) 2022 Entidad Pública Empresarial Red.es
 	*
 	* This file is part of "dge_ckan_php_client (datos.gob.es)".
 	*
 	* This program is free software: you can redistribute it and/or modify
 	* it under the terms of the GNU General Public License as published by
 	* the Free Software Foundation, either version 2 of the License, or
 	* (at your option) any later version.
 	*
 	* This program is distributed in the hope that it will be useful,
 	* but WITHOUT ANY WARRANTY; without even the implied warranty of
 	* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 	* GNU General Public License for more details.
 	*
 	* You should have received a copy of the GNU General Public License
 	* along with this program. If not, see <http://www.gnu.org/licenses/>.
 	*/

//namespace DGECKAN;
//
//use DateTime;
//use DateTimeZone;
//use Exception;

/**
 * Inspired by "https://github.com/GSA/ckan-php-client.git" and https://github.com/jeffreybarke/Ckan_client-PHP
 */
class DgeCkanClient
{

    /**
     * @var string
     */
    private $api_url = '';

    /**
     * @var null|string
     */
    private $api_key = null;

    /**
     * @var null|string
     */
    private $debug = false;

    /**
     * @var null|array
     */
    private $curl_request;

    /**
     * cURL handler
     * @var resource
     */
    private $curl_handler;


    /**
     * cURL headers
     * @var array
     */
    private $curl_headers;

    /**
     * HTTP status codes.
     * @var        array
     */
    private $http_status_codes = [
        '200' => 'OK',
        '301' => 'Moved Permanently',
        '400' => 'Bad Request',
        '403' => 'Not Authorized',
        '404' => 'Not Found',
        '409' => 'Conflict (e.g. name already exists)',
        '411' => 'Length required',
        '500' => 'Service Error',
        '503' => 'Service unavailable (e.g. CKAN build in progress, or you are banned)'
    ];

    /**
     * @param      $api_url
     * @param null $api_key
     * @param      $proxy_conf
     * @param      $debug
     */
    public function __construct($api_url, $api_key = null, $proxy_conf = array(), $debug = false)
    {
        $this->api_url = $api_url;
        $this->api_key = $api_key;

        $this->debug = $debug;

        // Create cURL object.
        $this->curl_handler = curl_init();
        // Follow any Location: headers that the server sends.
        curl_setopt($this->curl_handler, CURLOPT_FOLLOWLOCATION, true);
        // However, don't follow more than five Location: headers.
        curl_setopt($this->curl_handler, CURLOPT_MAXREDIRS, 5);
        // Automatically set the Referrer: field in requests
        // following a Location: redirect.
        curl_setopt($this->curl_handler, CURLOPT_AUTOREFERER, true);
        // Return the transfer as a string instead of dumping to screen.
        curl_setopt($this->curl_handler, CURLOPT_RETURNTRANSFER, true);
        // If it takes more than 5 minutes => fail
        curl_setopt($this->curl_handler, CURLOPT_TIMEOUT, 60 * 5);
        // We don't want the header (use curl_getinfo())
        curl_setopt($this->curl_handler, CURLOPT_HEADER, false);
        // Track the handle's request string
        curl_setopt($this->curl_handler, CURLINFO_HEADER_OUT, true);
        // Attempt to retrieve the modification date of the remote document.
        curl_setopt($this->curl_handler, CURLOPT_FILETIME, true);
        curl_setopt($this->curl_handler, CURLOPT_SSL_VERIFYPEER, false);

        // Proxy configurations (optional)
        if(isset($proxy_conf['proxy_server'])) {
            curl_setopt($this->curl_handler, CURLOPT_PROXY, $proxy_conf['proxy_server']);

            if(isset($proxy_conf['proxy_port']) && $proxy_conf['proxy_port'] != '')
                curl_setopt($this->curl_handler, CURLOPT_PROXYPORT, $proxy_conf['proxy_port']);

            if(isset($proxy_conf['proxy_type']) && $proxy_conf['proxy_type'] != '')
                curl_setopt($this->curl_handler, CURLOPT_PROXYTYPE, $proxy_conf['proxy_type']);

            if(isset($proxy_conf['proxy_username']) && $proxy_conf['proxy_username'] != '') {
                curl_setopt($this->curl_handler, CURLOPT_PROXYUSERPWD, $proxy_conf['proxy_username'].':'.$proxy_conf['proxy_password']);
                curl_setopt($this->curl_handler, CURLOPT_PROXYAUTH, CURLAUTH_NTLM);
            }

            if(isset($proxy_conf['proxy_user_agent']))
                curl_setopt($this->curl_handler, CURLOPT_USERAGENT, $proxy_conf['proxy_user_agent']);

            if(isset($proxy_conf['proxy_exceptions'])) {
                if (is_string($proxy_conf['proxy_exceptions'])){
                    curl_setopt($this->curl_handler, CURLOPT_NOPROXY, $proxy_conf['proxy_exceptions']);
                } elseif (is_array($proxy_conf['proxy_exceptions']) && !empty($proxy_conf['proxy_exceptions'])){
                    curl_setopt($this->curl_handler, CURLOPT_NOPROXY, implode(",", $proxy_conf['proxy_exceptions']));
                }
            }
        }

        // Initialize cURL headers
        $this->set_headers();
    }

    /**
     * Sets the custom cURL headers.
     * @access    private
     * @return    void
     * @since     Version 0.1.0
     */
    private function set_headers()
    {
        $date = new DateTime(null, new DateTimeZone('UTC'));
        $this->curl_headers = [
            'Date: ' . $date->format('D, d M Y H:i:s') . ' GMT', // RFC 1123
            'Accept: application/json',
            'Accept-Charset: utf-8',
            'Accept-Encoding: gzip',
            'Cookie: auth_tkt=foo'
        ];

        if ($this->api_key) {
            $this->curl_headers[] = 'Authorization: ' . $this->api_key;
        }
    }

    /**
     * @param $resource
     *
     * @return mixed
     * @throws \Exception
     * @link http://docs.ckan.org/en/latest/api/#ckan.logic.action.create.resource_create
     */
    public function resource_create($resource)
    {
        $data = json_encode($resource, JSON_PRETTY_PRINT);

        return $this->make_request(
            'POST',
            'action/resource_create',
            $data
        );
    }

    /**
     * @param string $method // HTTP method (GET, POST)
     * @param string $uri // URI fragment to CKAN resource
     * @param string $data // Optional. String in JSON-format that will be in request body
     *
     * @return mixed    // If success, either an array or object. Otherwise FALSE.
     * @throws Exception
     */
    private function make_request($method, $uri, $data = null)
    {
        $method = strtoupper($method);
        if (!in_array($method, ['GET', 'POST'])) {
            throw new Exception('Method ' . $method . ' is not supported');
        }
        // Set cURL URI.
        $url = strpos($uri, '//') ? $uri : $this->api_url . $uri;
        curl_setopt($this->curl_handler, CURLOPT_URL, $url);
        if ($method === 'POST' && $data) {
            curl_setopt($this->curl_handler, CURLOPT_POSTFIELDS, urlencode($data));
        } else {
            $method = 'GET';
        }

        $this->drupal_debug('CKAN request '.$method,array($url,$data));
        $this->setCurlRequest(array($url,$data));

        // Set cURL method.
        curl_setopt($this->curl_handler, CURLOPT_CUSTOMREQUEST, $method);

        // Set headers.
        curl_setopt($this->curl_handler, CURLOPT_HTTPHEADER, $this->curl_headers);
        // Execute request and get response headers.
        $response = curl_exec($this->curl_handler);
        $info = curl_getinfo($this->curl_handler);

        // Check HTTP response code
        if ($info['http_code'] !== 200) {
            $this->drupal_debug('CKAN response error',$info, 'error');
        }
        else {
          $this->drupal_debug('CKAN response OK',array($response));
        }
        return $response;
    }


    /**
     * @param $action
     * @param array $data
     * @return mixed
     */
    public function request($action, ...$data) {

      if(!in_array($action, get_class_methods($this))) {
        throw new Exception($action . ' do not exist');
      }
      $response = call_user_func_array(array($this, $action), $data);

      return json_decode($response, true);
    }

    /**
     * Return a list of the site’s tags.
     *
     * @param $data
     *
     * @return mixed
     * @link http://docs.ckan.org/en/latest/api/#ckan.logic.action.get.tag_list
     *  Params:
     *  query (string) – a tag name query to search for, if given only tags whose names contain this string will be
     *     returned (optional) vocabulary_id (string) – the id or name of a vocabulary, if give only tags that belong
     *     to this vocabulary will be returned (optional) all_fields (boolean) – return full tag dictionaries instead
     *     of just names (optional, default: False)
     */
    public function tag_list($data = null)
    {
        return $this->make_request(
            'POST',
            'action/tag_list',
            $data
        );
    }

    /**
     * @param $search
     *
     * @return mixed
     */
    public function api_resource_search($search)
    {
       // http: //catalog.data.gov/api/search/resource?url=explore.data.gov&all_fields=1&limit=100

        $query = http_build_query($search);

        return $this->make_request(
            'GET',
            'http://catalog.data.gov/api/search/resource?all_fields=1&limit=100&' . $query
        );
    }

    /**
     * Create a new vocabulary tag.
     *
     * @param      $name
     * @param null $vocabulary_id
     *
     * @return mixed
     * @link     http://docs.ckan.org/en/latest/api/#ckan.logic.action.get.tag_list
     *  Params:
     *  name (string) – the name for the new tag, a string between 2 and 100 characters long containing only
     *  alphanumeric characters and -, _ and ., e.g. 'Jazz'
     *  vocabulary_id (string) – the name or id of the vocabulary that the new tag should be added to, e.g. 'Genre'
     */
    public function tag_create($name, $vocabulary_id)
    {
        $data = [
            'name' => $name,
            'vocabulary_id' => $vocabulary_id,
        ];
        $data = json_encode($data, JSON_PRETTY_PRINT);

        return $this->make_request(
            'POST',
            'action/tag_create',
            $data
        );
    }

    /**
     * Return a list of all the site’s tag vocabularies.
     */
    public function vocabulary_list()
    {
        return $this->make_request('GET', 'action/vocabulary_list');
    }

    /**
     * Create a new tag vocabulary.
     *
     * @param $name
     *  Params:
     *  name (string) – the name for the new vocabulary, a string between 2 and 100 characters long containing only
     *     alphanumeric characters and -, _ and ., e.g. 'Jazz' tags (list of tag dictionaries) – the new tags to add to
     *     the new vocabulary, for the format of tag dictionaries see tag_create()
     *
     * @return mixed
     */
    public function vocabulary_create($name)
    {
        $data = [
            'name' => $name,
        ];
        $data = json_encode($data, JSON_PRETTY_PRINT);

        return $this->make_request(
            'POST',
            'action/vocabulary_create',
            $data
        );
    }

    /**
     * Return a list of the names of the site’s groups.
     *
     * @param bool $all_fields
     *
     * @return mixed
     * @link http://docs.ckan.org/en/latest/api/index.html#ckan.logic.action.get.group_list
     */
    public function group_list($all_fields = false)
    {
        $solr_request = [
            'all_fields' => $all_fields
        ];
        $data = json_encode($solr_request, JSON_PRETTY_PRINT);

        return $this->make_request(
            'POST',
            'action/group_list',
            $data
        );
    }

    /**
     * Searches for packages satisfying a given search criteria
     *
     * @param string $package_id (id/name)
     *
     * @return mixed
     * @link http://docs.ckan.org/en/latest/api/index.html#ckan.logic.action.get.package_show
     */
    public function package_show($package_id)
    {
        $solr_request = [
            'id' => $package_id
        ];
        $data = json_encode($solr_request, JSON_PRETTY_PRINT);

        return $this->make_request(
            'POST',
            'action/package_show',
            $data
        );
    }

    /**
     * Returns organization list
     *
     * @param $all_fields bool
     * @param $include_users bool
     *
     * @return mixed
     * @link http://docs.ckan.org/en/latest/api/index.html#ckan.logic.action.get.organization_list
     */
    public function organization_list($all_fields = false, $include_users = false)
    {
        if ($all_fields || ($all_fields && $include_users)) {
            return $this->make_request(
                'POST',
                'action/organization_list',
                json_encode(['all_fields' => $all_fields, 'include_users' => $include_users])
            );
        }
        return $this->make_request(
            'POST',
            'action/organization_list'
        );
    }

    /**
     * Returns organization with matching id or name
     *
     * @param string $organization_id (id/name)
     *
     * @return mixed
     * @link http://docs.ckan.org/en/latest/api/index.html#ckan.logic.action.get.organization_show
     */
    public function organization_show($organization_id, $include_datasets = False)
    {
        $solr_request = [
            'id' => $organization_id,
            'include_datasets' => $include_datasets
        ];
        $data = json_encode($solr_request, JSON_PRETTY_PRINT);

        return $this->make_request(
            'POST',
            'action/organization_show',
            $data
        );
    }

    /**
     * Create a new organization.
     *
     * @param      $name
     *
     * @return mixed
     * @link     http://docs.ckan.org/en/latest/api/index.html#ckan.logic.action.create.organization_create
     *  Params:
     *  name (string) – the name of the organization, a string between 2 and 100 characters long,
     *    containing only lowercase alphanumeric characters, - and _
     *  title (string) – the title of the organization (optional)
     *    extras (list of dataset extra dictionaries) – the organization’s extras (optional), extras are arbitrary (key: value)
     *    metadata items that can be added to organizations, each extra dictionary should have keys 'key' (a string),
     *  'value' (a string), and optionally 'deleted'
     *  example: array(array('key'=>'key_1','value'=>'value_1'),array('key'=>'key_2','value'=>'value_2'))
     *
     *
     */
    public function organization_create($name, $title = '', $extras = array())
    {
      $data = [
        'name' => $name,
        'title' => $title,
        'extras' => $extras
      ];
      $data = json_encode($data, JSON_PRETTY_PRINT);

      return $this->make_request(
        'POST',
        'action/organization_create',
        $data
      );
    }

    /**
     * Update a organization
     *
     * @param $data
     *
     * @return mixed
     * @link http://docs.ckan.org/en/latest/api/index.html#ckan.logic.action.update.organization_update
     *  Params:
     *  data (array) : formatted data, id required, example:
     *  {
     *    "id": "3d1b7a98-93c6-4c71-93e9-e5dd3ec653df",
     *    "name": "org_edited_1"
     *    "extras":   [
     *        {
     *          "key": "key1",
     *          "value": "value1",
     *          "deleted": true
     *        },
     *        {
     *          "key": "key2",
     *          "value": "value2"
     *        }
     *    ]
     *  }
     */
    public function organization_update(array $data)
    {
      $data = json_encode($data, JSON_PRETTY_PRINT);

      return $this->make_request(
        'POST',
        'action/organization_update',
        $data
      );
    }

    /**
     * Patch a organization
     *
     * @param $data
     *
     * @return mixed
     * @link http://docs.ckan.org/en/latest/api/index.html#ckan.logic.action.update.organization_patch
     *  Params:
     *  data (array) : formatted data, id required, example:
     *  {
     *    "id": "3d1b7a98-93c6-4c71-93e9-e5dd3ec653df",
     *    "name": "org_edited_1"
     *    "extras":   [
     *        {
     *          "key": "key1",
     *          "value": "value1",
     *          "deleted": true
     *        },
     *        {
     *          "key": "key2",
     *          "value": "value2"
     *        }
     *    ]
     *  }
     */
    public function organization_patch(array $data)
    {
      $data = json_encode($data, JSON_PRETTY_PRINT);

      return $this->make_request(
        'POST',
        'action/organization_patch',
        $data
      );
    }

    /**
     * @param $organization_id
     *
     * @return mixed
     *
     * @link http://docs.ckan.org/en/latest/api/index.html#ckan.logic.action.delete.organization_delete
     *
     * @throws \Exception
     */
    public function organization_delete($organization_id)
    {
      $data = [
        'id' => $organization_id,
      ];
      $data = json_encode($data, JSON_PRETTY_PRINT);

      return $this->make_request(
        'POST',
        'action/organization_delete',
        $data
      );
    }

    /**
     * Associate member to organization
     *
     * @param $organization_id
     * @param $username
     * @param $role
     *
     * @return mixed
     * @link     http://docs.ckan.org/en/latest/api/index.html#ckan.logic.action.create.organization_member_create
     *  Params:
     *  id (string) – the id or name of the organization
     *  username (string) – name or id of the user to be made member of the organization
     *  role (string) – role of the user in the organization. One of member, editor, or admin
     *
     * @throws \Exception
     */
    public function organization_member_create($organization_id, $username, $role)
    {
      $data = [
        'id' => $organization_id,
        'username' => $username,
        'role' => $role
      ];
      $data = json_encode($data, JSON_PRETTY_PRINT);

      return $this->make_request(
        'POST',
        'action/organization_member_create',
        $data
      );
    }

    /**
     * Associate member to organization
     *
     * @param $organization_id
     * @param $username
     *
     * @return mixed
     * @link     http://docs.ckan.org/en/latest/api/index.html#ckan.logic.action.delete.organization_member_delete
     *  Params:
     *  id (string) – the id or name of the organization
     *  username (string) – name or id of the user to be made member of the organization
     *
     * @throws \Exception
     */
    public function organization_member_delete($organization_id, $username)
    {
      $data = [
        'id' => $organization_id,
        'username' => $username,
      ];
      $data = json_encode($data, JSON_PRETTY_PRINT);

      return $this->make_request(
        'POST',
        'action/organization_member_delete',
        $data
      );
    }


    /**
     * Returns user with matching id or name
     *
     * @param string $user_id (id/name)
     *
     * @return mixed
     * @link http://docs.ckan.org/en/latest/api/index.html#ckan.logic.action.get.user_show
     */
    public function user_show($user_id)
    {
        $solr_request = [
            'id' => $user_id
        ];
        $data = json_encode($solr_request, JSON_PRETTY_PRINT);

        return $this->make_request(
            'POST',
            'action/user_show',
            $data
        );
    }

    /**
     * Create a new user.
     *
     * @param      $name
     * @param      $email
     * @param      $password
     *
     * @return mixed
     * @link     http://docs.ckan.org/en/latest/api/index.html#ckan.logic.action.create.user_create
     *  Params:
     * name (string) – the name of the new user, a string between 2 and 100 characters in length, containing only lowercase alphanumeric characters, - and _
     * email (string) – the email address for the new user
     * password (string) – the password of the new user, a string of at least 4 character
     *
     */
    public function user_create($name, $email, $password, $fullname)
    {
        $data = [
          'name' => $name,
          'email' => $email,
          'password' => $password,
          'fullname' => $fullname
        ];
        $data = json_encode($data, JSON_PRETTY_PRINT);

        return $this->make_request(
          'POST',
          'action/user_create',
          $data
        );
    }

    /**
     * Update a user
     *
     * @param $data
     *
     * @return mixed
     * @link http://docs.ckan.org/en/latest/api/index.html#ckan.logic.action.update.user_update
     *  Params:
     *  data (array) : formatted data, id required, example:
     *  {
     *    "id": "3d1b7a98-93c6-4c71-93e9-e5dd3ec653df",
     *    "name": "org_edited_1"
     *  }
     */
    public function user_update(array $data)
    {
      $data = json_encode($data, JSON_PRETTY_PRINT);

      return $this->make_request(
        'POST',
        'action/user_update',
        $data
      );
    }

    public function user_autocomplete($name)
    {
      return $this->make_request(
        'GET',
        'action/user_autocomplete?q=' . $name
      );
    }

  public function user_delete($user_id)
    {
        $solr_request = [
            'id' => $user_id,
        ];
        $data = json_encode($solr_request, JSON_PRETTY_PRINT);

        return $this->make_request(
            'POST',
            'action/user_delete',
            $data
        );
    }


    /**
     * @param $package_id
     *
     * @return mixed
     *
     * @link http://docs.ckan.org/en/latest/api/index.html#ckan.logic.action.delete.package_delete
     *
     * @throws \Exception
     */
    public function package_delete($package_id)
    {
        $solr_request = [
            'id' => $package_id,
        ];
        $data = json_encode($solr_request, JSON_PRETTY_PRINT);

        return $this->make_request(
            'POST',
            'action/package_delete',
            $data
        );
    }

    /**
     * Searches for packages satisfying a given search criteria
     *
     * @param        $q
     * @param        $fq
     * @param int $rows
     * @param int $start
     * @param string $sort
     *
     * @return mixed
     * @link http://docs.ckan.org/en/latest/api/index.html#ckan.logic.action.get.package_search
     */
    public function package_search($q = '', $fq = '', $rows = 100, $start = 0, $sort = 'score desc, name asc', $facet_field=null)
    {
        $solr_request = [
            'q' => $q,
            'fq' => $fq,
            'rows' => $rows,
            'start' => $start,
            'sort' => $sort
        ];
        if($facet_field){
            $solr_request['facet.field']=$facet_field;
        }
        $data = json_encode($solr_request, JSON_PRETTY_PRINT);

        return $this->make_request(
            'POST',
            'action/package_search',
            $data
        );
    }

    /**
     * @param             $member_id
     * @param string $object_type ('user', 'package')
     * @param string|bool $capacity ('member', 'editor', 'admin', 'public', 'private')
     *
     * @return mixed
     *
     * @link http://docs.ckan.org/en/latest/api/#ckan.logic.action.get.member_list
     */
    public function member_list($member_id, $object_type = 'package', $capacity = false)
    {
        $solr_request = [
            'id' => $member_id
        ];
        if ($object_type && ('none' != $object_type)) {
            $solr_request['object_type'] = $object_type;
        }
        if ($capacity) {
            $solr_request['capacity'] = $capacity;
        }
        $data = json_encode($solr_request, JSON_PRETTY_PRINT);

        return $this->make_request(
            'POST',
            'action/member_list',
            $data
        );
    }

    /**
     * Create a dataset (package)
     *
     * @param $data
     *
     * @return mixed
     * @link http://docs.ckan.org/en/latest/api/index.html#ckan.logic.action.update.package_create
     */
    public function package_create($data)
    {
        return $this->make_request(
            'POST',
            'action/package_create',
            $data
        );
    }

    /**
     * Update a dataset (package)
     *
     * @param $data
     *
     * @return mixed
     * @link http://docs.ckan.org/en/latest/api/index.html#ckan.logic.action.update.package_update
     */
    public function package_update(array $data)
    {
        $data = json_encode($data, JSON_PRETTY_PRINT);

        return $this->make_request(
            'POST',
            'action/package_update',
            $data
        );
    }

    /**
     * Get all packages
     *
     * @return mixed
     * @link http://docs.ckan.org/en/latest/api/index.html#ckan.logic.action.get.package_list
     */
    public function package_list($limit=null, $offset= null)
    {
      $query_string = '';
      if (is_int($limit) && is_int($offset)) {
        $query_string = '?limit=' . $limit . '&offset=' . $offset;
      }
      return $this->make_request(
        'GET',
        'action/package_list' . $query_string
      );
    }

    /**
     * Since it's possible to leave cURL open, this is the last chance to close it
     */
    public function __destruct()
    {
        if ($this->curl_handler) {
            curl_close($this->curl_handler);
            unset($this->curl_handler);
        }
    }

    /**
     * @return array|null
     */
    public function getCurlRequest() {
      return $this->curl_request;
    }

    /**
     * @param array|null $curl_request
     */
    public function setCurlRequest($curl_request) {
      $this->curl_request = $curl_request;
    }

    /**
     * If library is contained in drupal, then use watchdog
     *
     * @param $name
     * @param $vars
     * @param string $level
     */
    private function drupal_debug($name, $vars, $level = 'debug') {
      if($this->debug && function_exists('watchdog')) {
        if($level == 'error') {
          $wlevel = WATCHDOG_ERROR;
        }
        else {
          $wlevel = WATCHDOG_DEBUG;
        }
        watchdog('ckan_client', '!name: <pre>!export</pre>', array('!name' => $name, '!export' => print_r($vars, 1)), $wlevel);
      }
    }
}
