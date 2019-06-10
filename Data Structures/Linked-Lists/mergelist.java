//given two lists merge them alternatively
import java.util.*;
public class mergelist {
    public static Node[] mergeAlt(Node head1, Node head2) {
        Node next1 = null;
        Node next2 = null;
        // Node temp=null;
        Node[] arr = new Node[2];
        //stores answer
        Node ans = head1;
        Node current1 = head1;
        Node current2 = head2;
        while (current1 != null && current2 != null) {
            next1 = current1.next;
            next2 = current2.next;
            current1.next = current2;
            current2.next = next1;
            current1 = next1;
            current2 = next2;
        }
        arr[0] = ans;
        arr[1] = current2;
        return arr;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n1 = sc.nextInt();
        int a1 = sc.nextInt();
        head1 = insert(head1, a1);

        for (int i = 1; i < n1; i++) {
            int a = sc.nextInt();
            head1 = insert(head1, a);
        }
        int n2 = sc.nextInt();
        int a2 = sc.nextInt();
        head2 = insert(head2, a2);

        for (int i = 1; i < n2; i++) {
            int a = sc.nextInt();
            head2 = insert(head2, a);
        }
        Node res[] = mergeAlt(head1, head2);
        display(res[0]);
        display(res[1]);

    }
    // Class declaration for a Node of the Linked List
    static class Node {
        int data;
        Node next;

        public Node(int data) {
            this.data = data;
            this.next = null;
        }
    }
    static Node head1;
    static Node head2;
    //function to insert node
    public static Node insert(Node head, int data) {

        if (head == null) {
            return new Node(data);
        }

        head.next = insert(head.next, data);
        return head;
    }
    //function to print linkedlist
    public static void display(Node head) {
        for (Node node = head; node != null; node = node.next) {
            System.out.print(node.data + " ");
        }
        System.out.println();
    }

}