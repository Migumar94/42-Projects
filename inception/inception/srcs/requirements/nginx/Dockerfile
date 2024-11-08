# Debian image
FROM debian:bullseye

# Update & upgrade all packages
RUN apt update -y && apt upgrade -y
# Install nginx
RUN apt install -y nginx openssl curl

# Generate a self-signed SSL certificate and key
RUN mkdir -p /etc/nginx/ssl && \
    openssl req -x509 -nodes -days 42 -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=ES/ST=Andalucia/L=Malaga/O=42Malaga/OU=42/CN=inception"

# Change permissions and owner
RUN mkdir -p /var/www/html && \
    chown -R www-data:www-data /var/www/html

# Create the directory for Nginx runtime files
RUN mkdir -p /var/run/nginx

# Copy nginx config file
COPY conf/default.conf /etc/nginx/conf.d/default.conf
COPY conf/script.sh /usr/local/bin/script.sh
#SET PERMISSIONS
RUN chmod +x /usr/local/bin/script.sh
RUN chown -R www-data:www-data /var/www/html
#run script
CMD ["/usr/local/bin/script.sh"]

# Expose the port
EXPOSE 443
CMD ["nginx", "-g", "daemon off;"]
