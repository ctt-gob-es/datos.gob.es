# Copyright (C) 2022 Entidad Pública Empresarial Red.es
#
# This file is part of "dge_drupal_users (datos.gob.es)".
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.

from setuptools import setup, find_packages

version = '0.0.1'

setup(
    name='ckanext-dge-drupal-users',
    version=version,
    description="DGE Drupal Users",
    long_description="""\
       Based on the ckanext-drupal7 plugin created by Toby dacre (toby.dacre@okfn.org)
    """,
    classifiers=[], # Get strings from http://pypi.python.org/pypi?%3Aaction=list_classifiers
    keywords='',
    author='GMV',
    author_email='sgi@gmv.com',
    url='',
    license='',
    packages=find_packages(exclude=['ez_setup', 'examples', 'tests']),
    namespace_packages=['ckanext', 'ckanext.dge_drupal_users'],
    include_package_data=True,
    zip_safe=False,
    install_requires=[
        # -*- Extra requirements: -*-
    ],
    entry_points=\
    """
    [ckan.plugins]

    dge_drupal_users=ckanext.dge_drupal_users.plugin:DgeDrupalUsersPlugin
    """,
)
