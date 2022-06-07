<?php

/**
 	* Copyright (C) 2022 Entidad Pública Empresarial Red.es
 	*
 	* This file is part of "dge_sendinblue_php_client (datos.gob.es)".
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

require_once __DIR__.'/vendor/autoload.php';

class DgeSendInBlueClient
{
    private $max_number_request_tries;
    private $api_key;
    private $debug = false;
    private $config;

    private $foldersApiInstance;
    private $listsApiInstance;
    private $contactsApiInstance;
    private $accountApiInstance;

    public $list;
    public $account;
    public $list_id;

    public function __construct($api_key, $list_id = null, $debug = false, $max_number_request_tries = 3)
    {
        $this->max_number_request_tries  = $max_number_request_tries;
        $this->api_key                   = $api_key;
        $this->config                    = SendinBlue\Client\Configuration::getDefaultConfiguration()->setApiKey('api-key', $this->api_key);
        $this->foldersApiInstance        = new SendinBlue\Client\Api\FoldersApi(new GuzzleHttp\Client(), $this->config);
        $this->listsApiInstance          = new SendinBlue\Client\Api\ListsApi(new GuzzleHttp\Client(), $this->config);
        $this->contactsApiInstance       = new SendinBlue\Client\Api\ContactsApi(new GuzzleHttp\Client(), $this->config);
        $this->accountApiInstance        = new SendinBlue\Client\Api\AccountApi(new GuzzleHttp\Client(), $this->config);
        $this->emailCampaingsApiInstance        = new SendinBlue\Client\Api\EmailCampaignsApi(new GuzzleHttp\Client(), $this->config);
        $this->sendersApiInstance        = new SendinBlue\Client\Api\SendersApi(new GuzzleHttp\Client(), $this->config);

        if ($list_id) {
            try {
                $this->list_id = intval($list_id);
                $this->list    = $this->getList();
                $this->account = $this->getaccount();
            } catch (Exception $e) {
                throw  $e;
            }
        } else {
            throw new Exception('Faltan parametros');
        }
    }

    //siempre poner $tries en 0
    private function request_wrapper($function, $tries = 0, ...$args)
    {
        try {
            return call_user_func_array($function, $args);
        } catch (Exception $e) {
            if ($tries > $this->max_number_request_tries - 1) {
                throw $e;
            } else {
                return $this->request_wrapper($function, $tries + 1, ...$args);
            }
        }
    }

    private function getAccount()
    {
        try {
            $result = $this->request_wrapper([$this->accountApiInstance, 'getAccount']);

            return $result;
            //code...
        } catch (Exception $e) {
            //throw $th;
            throw  $e;
        }
    }

    private function getList()
    {
        try {
            $result = $this->request_wrapper([$this->contactsApiInstance, 'getList'], 0, $this->list_id);

            return $result;
            //code...
        } catch (Exception $e) {
            //throw $th;
            throw  $e;
        }
    }

    public function syncContactsToList($list)
    {
        if ('string' === gettype($list)) {
            $list = [$list];
        }
        try {
            $contacts_form_list           = $this->getContactsFromList();
            $no_existing_account_in_source=array_diff($contacts_form_list, $list);
            $this->removeContactFromList($no_existing_account_in_source);

            $this->addSubscriptorsToList($list);
        } catch (Exception $e) {
            throw  $e;
        }
    }

    // devuelve un array con todos los contactos de la lista
    public function getContactsFromAccount($offset = 0)
    {
        //el valor maximo para limit es 500 segun el api de sendinblue
        $limit = 500;
        try {
            $result = $this->request_wrapper([$this->contactsApiInstance, 'getContacts'], 0, $limit, $offset);
            if ($result->getContacts()) {
                $result = $result->getContacts();
                $result = array_map(function ($e) {
                    return $e['email'];
                }, $result);

                return array_merge($result, $this->getContactsFromAccount($offset + $limit));
            } else {
                return [];
            }
        } catch (Exception $e) {
            throw  $e;
        }
    }

    public function getContactsFromList($offset = 0)
    {
        //el valor maximo para limit es 500 segun el api de sendinblue
        $limit = 500;
        try {
            $result = $this->request_wrapper([$this->contactsApiInstance, 'getContactsFromList'], 0, $this->list_id, null, $limit, $offset);
            if ($result->getContacts()) {
                $result = $result->getContacts();
                $result = array_map(function ($e) {
                    return $e['email'];
                }, $result);

                return array_merge($result, $this->getContactsFromList($offset + $limit));
            } else {
                return [];
            }
        } catch (Exception $e) {
            throw  $e;
        }
    }
    public function createEmailCampaign($sender, $name,$subject,$html_content,$footer=null){
        $emailCampaigns = new \SendinBlue\Client\Model\CreateEmailCampaign(); // \SendinBlue\Client\Model\CreateEmailCampaign | Values to create a campaign
        $emailCampaignSender= new \SendinBlue\Client\Model\CreateEmailCampaignSender();
        $emailCampaignSender->setEmail($sender);
        $emailCampaigns->setSender($emailCampaignSender);
        $emailCampaigns->setName($name);
        $emailCampaigns->setSubject($subject);
        $emailCampaigns->setHtmlContent($html_content);
        $emailCampaigns->setFooter($footer);
        $recipients=new \SendinBlue\Client\Model\CreateEmailCampaignRecipients();
        $recipients->setListIds([$this->list_id]);

        $emailCampaigns->setRecipients($recipients);

        try {
            $campaing= $this->request_wrapper([$this->emailCampaingsApiInstance,'createEmailCampaign'],0,$emailCampaigns);
            return $campaing;
        } catch (Exception  $e) {
            throw  $e;
        }
    }
    public function sendEmailCampaignNow($campaign_id){
        try {
            //code...
            $campaing= $this->request_wrapper([$this->emailCampaingsApiInstance,'sendEmailCampaignNow'],0,$campaign_id);
        } catch (Exception  $e) {
            throw  $e;
        }
    }
    public function createSender($sender_email){
        $sender = new \SendinBlue\Client\Model\CreateSender(); // \SendinBlue\Client\Model\CreateSender | sender's name
        $sender->setName($sender_email);
        $sender->setEmail($sender_email);
        try {
            $result = $this->request_wrapper([$this->sendersApiInstance, 'createSender'], 0, $sender);
        } catch (Exception  $e) {
            throw  $e;
        }
    }
    //create un contacto y lo asgina a la lista
    private function createContact($email)
    {
        $createContact = new \SendinBlue\Client\Model\CreateContact(); // \SendinBlue\Client\Model\CreateContact | Values to create a contact
        $createContact->setEmail($email);
        $createContact->setListIds([$this->list_id]);
        try {
            $result = $this->request_wrapper([$this->contactsApiInstance, 'createContact'], 0, $createContact);
        } catch (Exception  $e) {
            throw  $e;
        }
    }

    //asigna uno o mas contactos ya existentes a la lista
    private function addContactToList($contacts)
    {
        if ('string' === gettype($contacts)) {
            $contacts = [$contacts];
        }
        $chunks=array_chunk($contacts, 150);
        foreach ($chunks as $chunk) {
            $contactEmails = new \SendinBlue\Client\Model\AddContactToList();

            $contactEmails->setEmails($chunk);
            try {
                $this->request_wrapper([$this->listsApiInstance, 'addContactToList'], 0, $this->list_id, $contactEmails);
            } catch (Exception $e) {
                throw $e;
            }
        }
    }

    //quita uno o mas contactos ya existentes a la lista
    public function removeContactFromList($contacts)
    {
        if ('string' === gettype($contacts)) {
            $contacts = [$contacts];
        }
        $chunks=array_chunk($contacts, 150);
        foreach ($chunks as $chunk) {
            $contactEmails = new \SendinBlue\Client\Model\RemoveContactFromList();

            $contactEmails->setEmails($chunk);
            try {
                $this->request_wrapper([$this->listsApiInstance, 'removeContactFromList'], 0, $this->list_id, $contactEmails);
            } catch (Exception $e) {
                throw $e;
            }
        }
    }

    // Asigna y/c crea uno o más contactos a la lista
    // $emails -> type: string or array
    public function addSubscriptorsToList($emails)
    {
        if ('string' === gettype($emails)) {
            $emails = [$emails];
        }

        $emails= array_map(function($e){
            return strtolower($e);
        },$emails);
        $contacts_form_account= $this->getContactsFromAccount();
        $no_existing_account  = array_diff($emails, $contacts_form_account);

        foreach ($no_existing_account as $email) {
            try {
                $this->createContact($email);
            } catch (Exception $e) {
                if ('duplicate_parameter' === $this->getValueResponse($e->getMessage())) {
                    continue;
                } else {

                    throw $e;
                }
            }
        }
        $contacts_form_list         = $this->getContactsFromList();
        $no_existing_account_in_list= array_diff($emails, $contacts_form_list);
        try {
            $this->addContactToList($no_existing_account_in_list);
        } catch (Exception $e) {
            if (! 'invalid_parameter' === $this->getValueResponse($e->getMessage()) ) { //&& !'duplicate_parameter'===$this->getValueResponse($e->getMessage())
                throw $e;
            }

        }
    }


    private function getResponse($string)
    {
        return json_decode(explode('response:', $string)[1]);
    }

    public function getValueResponse($string, $key = 1)
    {
        return explode(':', $string)[$key];
    }
}

try {
    // $client = new  DgeSendInBlueClient('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', null, 'datos.gob.es', 'dev-suscriptores');
    // $client = new  DgeSendInBlueClient('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', 55);
    // // $client = new  DgeSendInBlueClient('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', 14);
    // // $client->removeContactFromList('wcampossss@everis.com');
    // $cam=$client->createEmailCampaign('salfonzo@sia.es','primer boletin','primer boletin','<p><strong>hola mundo</strong></p>');
    // $client->sendEmailCampaignNow($cam->getId());
    // $client->createSender('datos@asdf.com');
    // var_dump($cam->getId());
    // $start  = microtime(true);
    // $list   = [];
    // foreach (range(11, 30) as $item) {
    //     array_push($list, "jperez$item@gmail.com");
    // }
    // $client->syncContactsToList($list);
    // $client->syncContactsToList('gersonhoyle@gmail.com');
    // $end  = microtime(true);
    // $time = number_format(($end - $start), 2);

    // // print_r($item);
    // echo PHP_EOL, $time, PHP_EOL;
} catch (Exception $e) {
    echo $e->getMessage();
}
