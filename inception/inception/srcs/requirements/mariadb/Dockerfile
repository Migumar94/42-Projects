# Debian image
FROM debian:bullseye

# Update & upgrade all packages
RUN apt update -y && apt upgrade -y

# Install mariadb
RUN apt install mariadb-server mariadb-client -y
RUN apt install curl -y

RUN apt-get clean && rm -rf var/lib/apt/lists/*

# Copy the MariaDB config file
COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/

# Initialize MariaDB
RUN mysql_install_db --user=mysql --datadir=/var/lib/mysql

EXPOSE 3306

# Copy and set permissions for the startup script
COPY conf/script.sh ./script.sh
RUN chmod +x ./script.sh

CMD ["/script.sh"]
