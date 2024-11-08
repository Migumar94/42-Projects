# Use the official Debian Bullseye image
FROM debian:bullseye

# Install necessary packages
RUN apt-get update && \
    apt-get install -y \
    php7.4-fpm \
    php7.4-mysql \
    php7.4-curl \
    php7.4-gd \
    php7.4-mbstring \
    unzip \
    curl

RUN mkdir /scripts
RUN useradd wp_user && groupadd wp_group && usermod -aG wp_group wp_user

# Create the /var/www/html/ directory and change its ownership
RUN mkdir -p /var/www/html && chown wp_user:wp_group /var/www/html

COPY conf/php-fpm.conf /etc/php/7.4/fpm/php-fpm.conf
COPY ./tools/wordpress.sh /scripts/wordpress.sh
COPY ./conf/wp-config.php /scripts/wp-config.php

RUN chmod +x /scripts/wordpress.sh

EXPOSE 9000

CMD ["/scripts/wordpress.sh"]