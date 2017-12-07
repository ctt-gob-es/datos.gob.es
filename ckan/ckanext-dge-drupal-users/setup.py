# Copyright (C) 2017 Entidad Pública Empresarial Red.es
# 
# This file is part of "ckanext-dge-drupal-users (datos.gob.es)".
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Affero General Public License as
# published by the Free Software Foundation, either version 3 of the
# License, or (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Affero General Public License for more details.
# 
# You should have received a copy of the GNU Affero General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# -*- coding: utf-8 -*-
from setuptools import setup, find_packages  # Always prefer setuptools over distutils

setup(
    name='ckanext-dge-drupal-users',
    version='1.0.0',
    description='',
    url='http://datos.gob.es',
    author='',
    author_email='',
    license='GNU Affero General Public License v3 or later (AGPLv3+)',

    classifiers=[
        'Development Status :: 5 - Production/Stable',
        'License :: OSI Approved :: GNU Affero General Public License v3 or later (AGPLv3+)',
        'Programming Language :: Python :: 2.7',
    ],


    # What does your project relate to?
    keywords='CKAN',

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
