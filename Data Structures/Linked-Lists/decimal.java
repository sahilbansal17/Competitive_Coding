//get decimal equivalent of binary number represented by linkedlist
import java.util.Scanner;
public class decimal {
    public static int func(Node head) 
    {
        Node temp = head;
        int ans = 0;
        int num = 0;
        while (temp != null) {
            if (temp.data == 1)
                ans = 2 * ans + 1;
            else
                ans = 2 * ans;
            temp = temp.next;
        }
        return ans;
    }
    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a1 = sc.nextInt();
        insert(a1);
        for (int i = 1; i < n; i++) {
            int a = sc.nextInt();
            insert(a);
        }
        int res = func(head);
        System.out.println(res);
    }
    private static class Node {
        int data;
        Node next;
        public Node(int data, Node next) 
        {
            this.data = data;
            this.next = next;
        }

    }
    static Node head;
    static Node tail;
    static int size;
    //insert node
    public static void insert(int data)
    {
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

    public static void display() 
    {
        for (Node node = head; node != null; node = node.next) 
        {
            System.out.print(node.data + " ");
        }
    }

}