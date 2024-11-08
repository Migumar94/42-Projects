#!/bin/bash


curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp
wp core download --allow-root --path=/var/www/html
cp /scripts/wp-config.php /var/www/html/wp-config.php

sed -i "s/database_name_here/$MYSQL_DATABASE/g" /var/www/html/wp-config.php
sed -i "s/username_here/$MYSQL_USER/g" /var/www/html/wp-config.php
sed -i "s/password_here/$MYSQL_PASSWORD/g" /var/www/html/wp-config.php
sed -i "s/localhost/$DB_HOST/g" /var/www/html/wp-config.php
wp core install --allow-root --path=/var/www/html \
	--url=$WP_URL --title=$WP_TITLE \
	--admin_user=$WP_ADMIN_USER --admin_password=$WP_ADMIN_PASSWORD \
	--admin_email=$WP_ADMIN_EMAIL

chown -R wp_user:wp_group /var/www/html && chmod -R 775 /var/www/html
php-fpm7.4 -y /etc/php/7.4/fpm/php-fpm.conf -F