import java.util.Scanner

fun main() {
    val read = Scanner(System.`in`)
    var t = read.nextInt()
    
    while (t>0) {
        t--
        var n = read.nextInt()
        var k = read.nextInt()
        
        var x = (1 + k + k*k + k*k*k)
        var ans = n/x
        
        print("${ans} ${ans*k} ${ans*k*k} ${ans*k*k*k}\n")
        
    }   
}