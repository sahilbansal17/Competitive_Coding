from random import randint


'''
Miller Rabin is a probabilistic approach in determining whether a number is a prime
or not.
For a more detailed explanation of Miller Rabin primality test and also for the
proof of its correctness refer:
https://www.cse.iitk.ac.in/users/manindra/CS681/2005/Lecture15.pdf
'''

#Modular Exponentiation to calculate (a^b)%mod
def fast_power(a: int,b: int,mod: int) -> int:
	power = 1

	while b:
		if b&1:
			power = (power*a)%mod

		a = (a*a)%mod
		b >>= 1

	return power


def miller_rabin(n: int,d: int) -> bool:
	a = randint(2,n-1) # a is a random number in [2,n-1]

	x = fast_power(a,d,n)

	if x == 1 or x == n-1:
		return True

	while d != n-1:
		x = (x*x)%n
		d *= 2

		if x == 1:
			return False

		elif x == n-1:
			return True

	return False


def isPrime(n: int,k = 10) -> bool:
	# Trivial Cases

	if n <= 1:
		return False

	if n == 2:
		return True

	if n%2 == 0:
		return False

	d = n-1
	while d%2 == 0:
		d = d//2

	while k:
		if miller_rabin(n,d) == False:
    			return False

		k -= 1

	return True

def main():
	t = int(input())

	for _ in range(t):
		n = int(input())

		if isPrime(n):
			print("prime")

		else:
			print("not prime")


if __name__ == "__main__":
	main()