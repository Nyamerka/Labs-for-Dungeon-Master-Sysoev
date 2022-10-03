echo "Купи слона!"
read otvet
while true
do
	echo "Все так говорят, а ты купи слона!"
	read otvet
	if [ "$otvet" = "Ставлю 5 без задачи" ]
	then
		echo "Спасибо, Добряшка)"
		break
	fi
done
