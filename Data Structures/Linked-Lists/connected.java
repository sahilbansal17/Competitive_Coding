//Given an array and a head pointer to a linkedlist
//find the number of connected components in a linkedlist
import java.util.*;
import java.io.*;
public class connected {
    public static int numComponents(Node n, int[] G) {
        //hashset to store the values of an array in order to check if 
        //data of current Node contributes to connected components 
        HashSet < Integer > hs = new HashSet < > ();
        for (int i = 0; i < G.length; i++) {
            hs.add(G[i]);
        }
        Node head = n;
        boolean flag = false;
        int ans = 0;
        while (head != null) {
            int num = head.data;
            if (hs.contains(num) && flag == false) {
                ans++;
                flag = true;
            } else if (!hs.contains(num)) {
                flag = false;
            }
            head = head.next;
        }
        return ans;
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
        int[] arr = new int[n2];
        for (int i = 0; i < n2; i++) {
            arr[i] = sc.nextInt();
        }
        System.out.println(numComponents(head1, arr));
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
    //inserting node in linkedlist
    static Node head1;
    public static Node insert(Node head, int data) {
        if (head == null) {
            return new Node(data);
        }
        head.next = insert(head.next, data);
        return head;
    }

}