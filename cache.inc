<?php

function _nasform_cached_data() {
  $my_data = &drupal_static(__FUNCTION__);
  $cache_id = 'nasform_select_name';

  if (!isset($my_data)) {
    if (($cache = cache_get('nasform_data' . $cache_id, 'cache_nasform')) && !empty($cache->data)) {
      $my_data = unserialize($cache->data);
      drupal_set_message(t('cached'));
    }
    else {
      $header = array(t('ID'), t('User name'), t('User login'), t('User email'), t('User pass'));
      $rows = array();
      $query = db_select('nasform_table', 't')
          ->fields('t', array('id', 'name', 'login', 'mail', 'pass'))
          ->execute();
      while ($value = $query->fetchAssoc()) {
        $rows[] = array(
          $value['id'],
          $value['name'],
          $value['login'],
          $value['mail'],
          $value['pass'],
          l(t('Update'), "nasform-page/{$value['id']}/update")
          . ' | '
          . l(t('Delete'), "nasform-page/{$value['id']}/delete"),
        );
      }
      $my_data = array('header' => $header, 'rows' => $rows);
      cache_set('nasform_data' . $cache_id, serialize($my_data), 'cache_nasform', 60 * 60);
    }
  }
  return theme('table', $my_data);
}