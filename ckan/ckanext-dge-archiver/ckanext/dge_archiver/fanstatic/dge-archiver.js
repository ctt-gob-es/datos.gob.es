/*
* Copyright (C) 2022 Entidad Pública Empresarial Red.es
*
* This file is part of "dge_archiver (datos.gob.es)".
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

const SELECTED_ORGS_SSK = 'selected-orgs';

$(function() {
   
    $.getJSON('checkeable-groups', function (obj) {
        let selected_orgs = [];
        if (obj != null && obj.hasOwnProperty('selected_orgs')){
            selected_orgs = obj.selected_orgs;
        }

        selected_orgs.forEach(function(org) {
            $(
                '#archiver-checkboxes input[type="checkbox"][data-org="' +
                    org +
                    '"]'
            ).prop('checked', true);
        });
    
        $('table#report-table tbody tr').each(function(i, tr) {
            const tr_jq = $(tr);
            if (
                selected_orgs.length > 0 &&
                !selected_orgs.includes(tr_jq.data('org'))
            ) {
                tr_jq.remove();
            }
        });
    
        $('#report-table').tablesorter();
    });

    $('#update-report-table').click(function(e) {
        e.preventDefault();

        const _selected_orgs = [];
        $('#archiver-checkboxes input[type="checkbox"]:checked').each(function(
            i,
            c_box
        ) {
            _selected_orgs.push($(c_box).data('org'));
        });

        $.ajax({
            url: 'checkeable-groups',
            method: 'POST',
            data: { object: _selected_orgs }
        }).success(function() {
            window.location.reload();
        });


        return false;
    });
});

//This js shows the % bar
function move(x, y, value, bar) {
    var elem = bar;
    var width = 0;
    var id = setInterval(frame, 10);
    function frame() {
        if (width >= value) {
            clearInterval(id);
            elem.innerHTML = x + '/' + y;
        } else {
            width++;
            elem.style.width = width + '%';
            elem.innerHTML = x + '/' + y;
        }
        if (width <= 10) {
            elem.style.width = 10 + '%';
        }
    }
}

var partial1 = document.getElementById('partial1').innerText;
var total1 = document.getElementById('total1').innerText;
var result1 = Math.round((partial1 / total1) * 100);
var bar1 = document.getElementById('broken_datasets_bar');
document.getElementById('broken_datasets_bar').innerHTML = move(
    partial1,
    total1,
    result1,
    bar1
);

var partial2 = document.getElementById('partial2').innerText;
var total2 = document.getElementById('total2').innerText;
var result2 = Math.round((partial2 / total2) * 100);
var bar2 = document.getElementById('broken_links_bar');
document.getElementById('broken_links_bar').innerHTML = move(
    partial2,
    total2,
    result2,
    bar2
);

//$(document).ready(function(){$(".spacious-container").floatingScrollbar();});

var expanded = false;

document.getElementById('archiver-select-search').value = '';

function showBoxes() {
    var checkboxes = document.getElementById('archiver-checkboxes');

    if (!expanded) {
        checkboxes.style.display = 'block';
        expanded = true;
    } else {
        checkboxes.style.display = 'none';
        expanded = false;
    }
}

window.addEventListener('click', function(e) {
    var container = document.getElementById('block-broken-groups');

    if (
        !container.contains(e.target) ||
        e.target.id === 'block-broken-groups'
    ) {
        var checkboxes = document.getElementById('archiver-checkboxes');
        checkboxes.style.display = 'none';
        expanded = false;
    }
});

function filterFunction() {
    var input = document.getElementById('archiver-select-search');
    var filter = input.value;
    var container = document.getElementById('archiver-checkboxes');
    var results = container.getElementsByTagName('label');
    console.log(container.scrollTop);
    for (i = 0; i < results.length; i++) {
        textValue = results[i].textContent || results[i].innerText;
        if (textValue.indexOf(filter) > -1) {
            results[i].style.display = '';
        } else {
            results[i].style.display = 'none';
        }
    }
}

$('.archiver-selectBox').on('click', function() {
    showBoxes();
});

$('#archiver-select-search').on('keyup', function() {
    filterFunction();
});
