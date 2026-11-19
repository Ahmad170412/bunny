.PHONY: run clean

run:
	python3 bunny.py welcome.txt

clean:
	rm -rf __pycache__
