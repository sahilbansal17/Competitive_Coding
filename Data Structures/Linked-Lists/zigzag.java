//get linkedlist in zigzag form (a < b > c < d > e < f )
import java.util.Scanner;
public class zigzag {
    public static void fashion(Node head) {
        int flag = 1;
        //counter variable to keep track if < or >
        Node prev = head;
        Node curr = head.next;
        while (curr != null) {
            if (flag % 2 != 0)
            // if flag is odd < operation
            {
                if (prev.data > curr.data) {
                    int temp = prev.data;
                    prev.data = curr.data;
                    curr.data = temp;
                }
                flag++;
                prev = prev.next;
                curr = curr.next;
            } else
            // if flag even > operation
            {
                if (prev.data < curr.data) {
                    int temp = prev.data;
                    prev.data = curr.data;
                    curr.data = temp;
                }
                flag++;
                prev = prev.next;
                curr = curr.next;
            }
        }
    }
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a1 = sc.nextInt();
        insert(a1);
        for (int i = 1; i < n; i++) {
            int a = sc.nextInt();
            insert(a);
        }
        fashion(head);
        display();
    }
    private static class Node {
        int data;
        Node next;
        public Node(int data, Node next) {
            this.data = data;
            this.next = next;
        }
    }
    static Node head;
    static Node tail;
    static int size;
    public static void insert(int data) {
        Node nn = new Node(data, null);
        if (head == null) {
            head = nn;
            tail = nn;
        } else {
            tail.next = nn;
            tail = nn;
        }
        size++;
    }
    public static void display() {
        for (Node node = head; node != null; node = node.next) {
            System.out.print(node.data + " ");
        }
    }

}