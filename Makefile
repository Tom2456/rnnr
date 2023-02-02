all: rnnr clean

rnnr:
	cd build/ && gcc ../*.c -c
	gcc build/*.o -o rnnr

clean:
	rm build/*

install:
	sudo cp rnnr /bin/ 
