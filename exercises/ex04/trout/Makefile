trout: trout.h util.h trout.c util.c
	gcc -g -o trout trout.c util.c

util: util.h util.c
	gcc -g -o util util.c

main: main.c trout.h trout.c util.c
	gcc -g -o main main.c trout.c util.c
