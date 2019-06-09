//this code removes duplicates from an unsorted list
import java.util.*;
public class duplicates {
    public static Node removeDuplicates(Node head) {
        //hashset to keep track of all unique values
        HashSet < Integer > hs = new HashSet < Integer > ();
        Node temp = head;
        Node prev = null;
        Node curr = head;
        while (curr != null) {
            int num = curr.data;
            //if value is not present in hashset add the value in hashset 
            if (!hs.contains(num)) {
                hs.add(num);
                prev = curr;
                curr = prev.next;
            } else
            // if found in hashset,delete the node having suplicate value
            {
                prev.next = curr.next;
                curr = curr.next;
            }
        }
        return temp;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a1 = sc.nextInt();
        head = insert(head, a1);
        for (int i = 1; i < n; i++) {
            int a = sc.nextInt();
            head = insert(head, a);
        }
        head = removeDuplicates(head);
        display(head);
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
    static Node head;
    public static Node insert(Node head, int data) {
        if (head == null) {
            return new Node(data);
        }

        head.next = insert(head.next, data);
        return head;
    }
    public static void display(Node head) {
        for (Node node = head; node != null; node = node.next) {
            System.out.print(node.data + " ");
        }
    }
}
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