<?php
/**
 * @file
 * Contains description of administrative forms.
 * User: Anastasiia Granko
 * Date: 25.11.15
 */

/**
 * Form constructor for page of administer.
 */
function nasform_page_admin_settings($form, $form_values) {
  $form = array();
  $form['user-name'] = array(
    '#type' => 'textfield',
    '#title' => t('Header field of user name'),
    '#default_value' => variable_get(t('user-name')),
    '#size' => 20,
  );
  $form['user-login'] = array(
    '#type' => 'textfield',
    '#title' => t('Header field of user login'),
    '#default_value' => variable_get(t('user-login')),
    '#size' => 20,
  );
  $form['user-mail'] = array(
    '#type' => 'textfield',
    '#title' => t('Header field of user email'),
    '#default_value' => variable_get(t('user-mail')),
    '#size' => 20,
  );
  $form['user-pass'] = array(
    '#type' => 'textfield',
    '#title' => t('Header field of user password'),
    '#default_value' => variable_get(t('user-pass')),
    '#size' => 20,
  );
  $form['user-gender'] = array(
    '#type' => 'textfield',
    '#title' => t('Header field of user gender'),
    '#default_value' => variable_get(t('user-gender')),
    '#size' => 20,
  );
//dpm($form);
  return system_settings_form($form);
}
/**
 * Saved header values passed in the form of user.
 */
function nasform_page_admin_settings_submit($form, &$form_values) {
  //dsm($form_values);
  variable_set('user-name', $form_values['values']['user-name']);
  variable_set('user-login', $form_values['values']['user-login']);
  variable_set('user-mail', $form_values['values']['user-mail']);
  variable_set('user-pass', $form_values['values']['user-pass']);
  variable_set('user-gender', $form_values['values']['user-gender']);
}