import java.util.Scanner
import kotlin.math.*

fun solve (a1: Int, b1: Int, a2: Int, b2: Int) : String {
    val t1 = min(a1, b1)
    val t2 = max(a1, b1)
    val u1 = min(a2, b2)
    val u2 = max(a2, b2)
    if (t2 == u1 && t1 + u2 == t2) return "Yes"
    else if (t2 == u2 && t1 + u1 == t2) return "Yes"
    else if (t1 == u1 && t2 + u2 == t1) return "Yes"
    else if (t1 == u2 && t2 + u1 == t1) return "Yes"
    else return "No"
}

fun main() {
    val reader = Scanner(System.`in`)
    val testcases = reader.nextInt()
    for (i in 1..testcases) {
        val a1 = reader.nextInt()
        val b1 = reader.nextInt()
        val a2 = reader.nextInt()
        val b2 = reader.nextInt()
        println(solve(a1, b1, a2, b2))
    }
}