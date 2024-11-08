#!/bin/bash
set -e

# Check if MySQL data directory exists and initialize if not
echo "MySQL data directory not found. Initializing..."
chown -R mysql:mysql /var/lib/mysql

  # Initialize MySQL data directory
mysql_install_db --basedir=/usr --datadir=/var/lib/mysql --user=mysql --rpm

# Check if the WordPress database is already created
if [ ! -d "/var/lib/mysql/${MYSQL_DATABASE}" ]; then
  echo "Creating ${MYSQL_DATABASE} database and user..."

  cat <<EOF >create_db.sql
USE mysql;
FLUSH PRIVILEGES;
DELETE FROM mysql.user WHERE User='' OR User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1');
DROP DATABASE IF EXISTS test;
DELETE FROM mysql.db WHERE Db='test';
CREATE USER IF NOT EXISTS 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};
ALTER DATABASE ${MYSQL_DATABASE} CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
GRANT CREATE, ALTER, DROP, INDEX, LOCK TABLES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
FLUSH PRIVILEGES;
EOF

  # Start MySQL/MariaDB and execute SQL commands
  mysqld --user=mysql --bootstrap <create_db.sql

  # Check if mysqld startup was successful
  if [ $? -ne 0 ]; then
    echo "Failed to start MySQL/MariaDB and execute initialization SQL."
    exit 1
  fi

  echo "${MYSQL_DATABASE} database and user created successfully."

else
  echo "${MYSQL_DATABASE} database already exists. Skipping creation."
fi

# Start MySQL/MariaDB server again
echo "Starting MySQL/MariaDB server..."
mysqld_safe --user=mysql &

exec mysqld 