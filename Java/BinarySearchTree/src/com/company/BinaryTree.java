package com.company;

public class BinaryTree<T extends Comparable<T>> {

    private class Node {
        private T value;
        private Node left;
        private Node right;

        Node(T value) {
            this.value = value;
            right = null;
            left = null;
        }
    }

    private Node root;

    private Node insertRecursive(Node current, T value) {
        int compareValue=value.compareTo(current.value);
        if (current == null) {
            return new Node(value);
        }

        if (compareValue<0) {
            current.left = insertRecursive(current.left, value);
        } else if (compareValue==1) {
            current.right = insertRecursive(current.right, value);
        } else {
            return current;
        }
        return current;
    }

    private boolean findRecursive(Node current, T value) {
        if (current == null) {
            return false;
        }
        if (value == current.value) {
            return true;
        }
        return value.compareTo(current.value)<0 ? findRecursive(current.left, value)  : findRecursive(current.right, value);
    }

    //Обход дерева «Левый-Корень-Правый
    public void printInOrder(Node node) {
        if (node != null) {
            printInOrder(node.left);
            System.out.print(node.value+" ");
            printInOrder(node.right);
        }
    }

    //Обход дерева «Корень-Левый-Правый»
    public void printPreOrder(Node node) {
        if (node != null) {
            System.out.print(node.value+" ");
            printPreOrder(node.left);
            printPreOrder(node.right);
        }
    }

    //Обход дерева «Левый-Правый-Корень»
    public void printPostOrder(Node node) {
        if (node != null) {
            printPostOrder(node.left);
            printPostOrder(node.right);
            System.out.print(node.value+" ");
        }
    }


    public boolean find(T value) {
        return findRecursive(root, value);
    }
    public void insert(T value) {
        root = insertRecursive(root, value);
    }
    public Node getRoot(){return root;}

}
