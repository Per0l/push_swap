import random
import sys

generated = []

if __name__ == "__main__":
	
	for i in range(int(sys.argv[1])):
		nbr = random.randint(0, 999)
		if not nbr in generated:
			generated.append(nbr)
			#print("\""+str(nbr)+"\",", end=" ")
			print(nbr, end = " ")