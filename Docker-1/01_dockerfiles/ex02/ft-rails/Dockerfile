FROM	ruby
RUN		apt-get update -y && \
		apt-get upgrade -y && \
		apt-get install -y sqlite3 nodejs

#	sqlite3		предпочитаемая БД для Ruby-On-Rails
#	nodejs		пакет-установщик для исполнения javascript-кода; нужен для некоторых gem-ов

ONBUILD COPY	app /opt/app
ONBUILD WORKDIR	/opt/app
ONBUILD RUN		bundle install
ONBUILD RUN		bundle exec rake db:migrate
ONBUILD RUN		bundle exec rake db:seed
ONBUILD EXPOSE	3000

#	docker build -t ft-rails:on-build .