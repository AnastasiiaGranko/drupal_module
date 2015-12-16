<?php
function _nasform_element_info() {
    $types['nasform_phonenumber_combined'] = array(
    '#input' => TRUE ,
    '#process' => array('nasform_phonenumber_combined_process'),
    '#autocomplete_path' => FALSE,
    '#default_value' => array(
      'areacode' => ''
    ),
  );
  return $types;
}

function nasform_phonenumber_combined_process($element, &$form_state, $complete_form) {

  $element['areacode'] = array(
    '#title' => t('Phone number'),
    '#type' => 'textfield',
    '#size' => 200,
    '#maxlength' => 200,
  );
     return $element;
}