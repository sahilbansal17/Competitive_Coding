import java.util.*
import kotlin.math.*
 
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong()
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of ints

fun main() {
    val T = readInt()
    for (t in 1..T) {
    	var n = readInt()
    	var d = 1
    	val summands = mutableListOf<Int>()
    	while(n > 0) {
    		val x = n % 10
    		if (x != 0) {
    			summands.add(x*d)
    		}
    		n /= 10
    		d *= 10
        }
    	println(summands.size)
    	println(summands.joinToString(" "))
    }
}