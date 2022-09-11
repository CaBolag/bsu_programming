package com.company;

public class Main {
    public static void main(String[] args) {
        BinaryTree<Person> binaryTree = new BinaryTree<>();
        Person person1=new Person("A",6);
        Person person2=new Person("B",4);
        Person person3=new Person("C",2);
        Person person4=new Person("D",9);
        Person person5=new Person("E",7);
        Person person6=new Person("F",10);
        Person person7=new Person("G",12);

        binaryTree.insert(person1);
        binaryTree.insert(person2);
        binaryTree.insert(person3);
        binaryTree.insert(person3);
        binaryTree.insert(person4);
        binaryTree.insert(person5);
        binaryTree.insert(person6);
        binaryTree.insert(person7);

        binaryTree.printPreOrder(binaryTree.getRoot());
        System.out.println();
        binaryTree.printInOrder(binaryTree.getRoot());
        System.out.println();
        binaryTree.printPostOrder(binaryTree.getRoot());
        System.out.println();

        System.out.println(binaryTree.find(person2));
        Person person8=new Person("H",12);
        System.out.println(binaryTree.find(person8));




        BinaryTree<Integer> binaryTreeNumber=new BinaryTree<>();
        binaryTreeNumber.insert(6);
        binaryTreeNumber.insert(4);
        binaryTreeNumber.insert(2);
        binaryTreeNumber.insert(9);
        binaryTreeNumber.insert(7);
        binaryTreeNumber.insert(10);
        binaryTreeNumber.insert(12);

        binaryTreeNumber.printPreOrder(binaryTreeNumber.getRoot());
        System.out.println();
        binaryTreeNumber.printInOrder(binaryTreeNumber.getRoot());
        System.out.println();
        binaryTreeNumber.printPostOrder(binaryTreeNumber.getRoot());
        System.out.println();


    }
}
