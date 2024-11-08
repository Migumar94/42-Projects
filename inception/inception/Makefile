# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/05 18:30:53 by migumar2          #+#    #+#              #
#    Updated: 2024/10/08 21:10:49 by migumar2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

name = inception

all:
	@docker compose -f ./srcs/docker-compose.yml down
	@mkdir -p /home/migumar2/data/mariadb
	@mkdir -p /home/migumar2/data/wordpress
	@docker compose -f ./srcs/docker-compose.yml up --build

build:
	@docker compose -f ./srcs/docker-compose.yml down
	@mkdir -p /home/migumar2/data/mariadb
	@mkdir -p /home/migumar2/data/wordpress
	@docker compose -f ./srcs/docker-compose.yml build

down:
	@docker compose -f ./srcs/docker-compose.yml down

clean:
	@docker compose -f ./srcs/docker-compose.yml down
	@printf "working...\n"
	@docker system prune -a -f  > /dev/null 2>&1
	@printf "dockers cleaned\n"

fclean:
	@docker compose -f ./srcs/docker-compose.yml down
	@printf "working...\n"
	@docker run --rm -v /home/migumar2/data:/data alpine sh -c "chmod -R 777 /data" > /dev/null 2>&1
	@docker system prune -a --volumes -f > /dev/null 2>&1
	@rm -rf /home/migumar2/data
	@printf "dockers cleaned and removed\n"

.PHONY: all build down clean fclean