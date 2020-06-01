import java.util.*
import kotlin.math.*
 
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong()
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of ints

fun main () {
    var t = readInt()
    for (i in 1..t) {
        var n = readInt()
        var s = readInts()
        var minDiff = 1000
        for (j in 0..(n-1)) {
            for (k in (j+1)..(n-1)) {
                if (abs(s[j] - s[k]) < minDiff) {
                    minDiff = abs(s[j] - s[k])
                }
            }
        }
        println(minDiff)
    }
}