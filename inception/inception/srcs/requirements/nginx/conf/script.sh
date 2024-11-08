#!/bin/bash

echo "Waiting for PHP-FPM to start..."
until nc -z -v -w30 wordpress 9000 > /dev/null 2>&1; do
  sleep 1
done
echo "PHP-FPM is up and running!"