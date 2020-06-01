import java.util.Scanner

fun add(a: Int, b: Int) : Int {
    return a+b
}

fun main() {
    val reader = Scanner(System.`in`)
    val testcases = reader.nextInt()
    for (i in 1..testcases) {
        val a = reader.nextInt()
        val b = reader.nextInt()
        println(add(a, b))
    }
}