image_id=$(docker ps -a | grep linux_env | awk '{print $1}')

if [ $image_id ]; then
	docker start $image_id
	docker attach $image_id
else
	docker build -t linux_env .
	docker run -it -v $PWD/:/tmp -w /tmp linux_env
fi