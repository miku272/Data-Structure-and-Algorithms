class Node<T> {
  T value;
  Node<T>? next;

  Node(this.value, {this.next});

  @override
  String toString() {
    if (next == null) return '$value\nEnd of link';

    return '$value -> ${next.toString()}';
  }
}

class LinkedList<E> extends Iterable<E> {
  Node<E>? head;
  Node<E>? tail;

  @override
  bool get isEmpty => head == null;

  void push(E value) {
    head = Node(value, next: head);

    tail ??= head;
  }

  void append(E value) {
    if (isEmpty) {
      push(value);
      return;
    }

    tail!.next = Node(value);

    tail = tail!.next;
  }

  Node<E>? nodeAt(int index) {
    var currentNode = head;
    var currentIndex = 0;

    while (currentNode != null && currentIndex < index) {
      currentNode = currentNode.next;
      currentIndex++;
    }

    return currentNode;
  }

  Node<E> insertAfter(Node<E> node, E value) {
    if (tail == node) {
      append(value);
      return tail!;
    }

    node.next = Node(value, next: node.next);

    return node.next!;
  }

  E? pop() {
    final value = head?.value;
    head = head?.next;

    if (isEmpty) {
      tail = null;
    }

    return value;
  }

  E? removeLast() {
    if (head?.next == null) return pop();

    var current = head;

    while (current!.next != tail) {
      current = current.next;
    }

    final value = tail?.value;
    tail = current;
    tail?.next = null;

    return value;
  }

  E? removeAfter(Node<E> node) {
    final value = node.next?.value;

    if (node.next == tail) {
      tail = node;
    }

    node.next = node.next?.next;

    return value;
  }

  @override
  String toString() {
    if (isEmpty) return 'List is empty';

    return head.toString();
  }

  @override
  Iterator<E> get iterator => throw UnimplementedError();
}

void main(List<String> args) {
  final list = LinkedList<double>();

  list.push(5);
  list.push(4);
  list.push(3);
  list.push(2);
  list.push(1);

  list.append(6);
  list.append(7);
  list.append(8);
  list.append(9);
  list.append(10);

  var middleNode = list.nodeAt(2)!;
  list.insertAfter(middleNode, 3.1);

  print('Popped value: ${list.pop()}');

  list.removeAfter(list.nodeAt(1)!);

  print(list);
}
