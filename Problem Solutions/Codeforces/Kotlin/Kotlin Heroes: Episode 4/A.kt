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
    for (t in 0 until T) {
        var (n, k) = readInts()
        var x = n/(1 + k + k*k + k*k*k)
        println("${x} ${x*k} ${x*k*k} ${x*k*k*k}")
    }
}