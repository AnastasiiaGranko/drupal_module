<?php
/**
 * @file
 * Page with iframe video.
 */
?>

<div align="center">
  <?php if ($video_link == ''): ?>
    <?php print t('Better to see this video!');
    $video_link = 'QGJuMBdaqIw';
    ?>
  <?php endif; ?>
  <iframe width="520" height="400" frameborder="0" allowfullscreen="1"
          style="display: block; padding: 0 0 0 300px; margin-top: 50px"
          src="
          <?php
          echo "http://www.youtube.com/embed/" . $video_link;
          ?>
           ">
  </iframe>
</div>
