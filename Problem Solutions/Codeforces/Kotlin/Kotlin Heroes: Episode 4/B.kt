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
        var (n, k1, k2) = readInts()
        var s = readLn()
        var maxLectures = 0
        var curCount = 0
        k2 = min(k2, 2*k1)
        for (i in 0 until (n + 1)) {
            if (i < n && s[i] == '1') {
                ++curCount
            } else if (curCount == 1) {
                maxLectures += k1
                curCount = 0
            } else {
                if (curCount % 2 == 1) {
                    maxLectures += (curCount/2)*k2 + max(k1, k2 - k1)
                } else {
                    maxLectures += (curCount/2)*k2
                }
                curCount = 0
            }
        }
        println(maxLectures)
    }
}