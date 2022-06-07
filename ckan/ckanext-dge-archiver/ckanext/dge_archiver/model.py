# Copyright (C) 2022 Entidad Pública Empresarial Red.es
#
# This file is part of "dge_archiver (datos.gob.es)".
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

import datetime

from sqlalchemy import types, Table, Column, Index, MetaData
from sqlalchemy.exc import SQLAlchemyError
from sqlalchemy.orm import mapper

from ckan import model
from ckan.model import Group

__all__ = ['CheckGroupArchiver', 'check_group_archiver_table', 'init_tables']

metadata = MetaData()

check_group_archiver_table = Table(
    'check_group_archiver', metadata,
    Column('id', types.UnicodeText, primary_key=True, default=model.types.make_uuid),
    Column('group_id', types.UnicodeText),
    Column('checkeable', types.Boolean, default=False),
)


class CheckGroupArchiver(object):
    '''
	CheckGroupArchiver saves a registry of wich organizations are going to have their resources checked with the archiver extension of CKAN
	'''

    def __init__(self, **kwargs):
        for k, v in kwargs.items():
            setattr(self, k, v)

    @classmethod
    def get(cls, group_id=None):
        CheckGroupArchiver({'group_id': '12312-qaeqwqwe-123', 'checkeable': True})
        '''
		Retrieves all the rows if group_id is not specified, retrieves one if it is specified
		'''
        item = None
        if group_id:
            item = model.Session.query(group.id).filter(group.name.in_(Names)).all()
            # item = model.Session.query(cls).filter(cls.group_id == group_id).first()
        else:
            item = model.Session.query(cls)

        return item

    @classmethod
    def all(cls):
        """
		Returns all groups.
		"""
        return model.Session.query(cls).all()

    def toggle_check(cls, group_id):
        '''
		Set to True or False if archiver can check all of the resources of the group specified, depending of the actual value in DB
		'''
        item = model.Session.query(cls).filter(cls.group_id == group_id).first()

        if item:
            item.checkeable = False if item.checkeable else True

    @classmethod
    def add_org(cls, org):
        org_to_add = CheckGroupArchiver(**{'group_id': org, 'checkeable': True})
        print (org_to_add.group_id)
        model.Session.add(org_to_add)

    @classmethod
    def commit(cls):
        try:
            model.Session.commit()
        except SQLAlchemyError as e:
            error = str(e.__dict__['orig'])
            return error


mapper(CheckGroupArchiver, check_group_archiver_table)


def init_tables():
    metadata.create_all(model.meta.engine)


def drop_tables():
    metadata.drop_all(model.meta.engine)
