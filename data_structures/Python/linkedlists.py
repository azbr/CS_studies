""" Simple Linked List. """

class Node:
    """ Element of a linked list.
    Contains a key and points to the next element. """

    def __init__(self, key, next_element=None):
        self.key = key
        self.next_element = next_element


class SimpleLinkedList:
    """ Implementation of a Linked List. """

    def __init__(self):
        self.begin = None
        self.end = None

    def contains(self, key):
        element = self.begin
        while element is not None and element.key != key:
            element = element.next_element

        return element is not None

    def insert(self, key):
        new_element = Node(key=key, next_element=self.begin)
        self.begin = new_element
        if self.end is None:
            self.end = new_element

    def insert_last(self, key):
        new_element = Node(key=key, next_element=None)

        if self.begin is None:
            self.begin = new_element
            self.end = new_element
        else:
            last_element = self.end
            last_element.next_element = new_element
            self.end = new_element

    def remove(self, key):
        if self.begin is None:
            return

        if self.begin.key == key:
            self.begin = self.begin.next_element
        else:
            previous = self.begin
            while previous.next_element is not None and previous.next_element.key != key:
                previous = previous.next_element

            if previous.next_element is None:
                return
            else:
                previous.next_element = previous.next_element.next_element

    def remove_last(self):
        if self.begin is None:
            return
        elif self.begin.next_element is None:
            self.begin = None
            self.end = None
            return

        previous_last = self.begin
        while previous_last.next_element.next_element is not None:
            previous_last = previous_last.next_element

        previous_last.next_element = None
        self.end = previous_last


""" Doubly Linked List. """

class DNode(Node):
    """ Element of a doubly linked list.
        Contains a key and points to the next and to the previous element. """

    def __init__(self, key, previous_element=None, next_element=None):
        super().__init__(key, next_element)
        self.previous_element = previous_element


class DoublyLinkedList(SimpleLinkedList):
    """ Implementation of a doubly linked list inherited from the simple linked list."""

    def __init__(self):
        super().__init__()

    def insert(self, key):
        new_element = DNode(key, previous_element=None, next_element=self.begin)
        if self.begin is not None:
            self.begin.previous_element = new_element
        else:
            self.end = new_element
        self.begin = new_element

    def remove(self, key):
        element = self.begin
        while element is not None and element.key != key:
            element = element.next_element
        if element is None:
            return

        if element.previous_element is not None:
            element.previous_element = element.next_element
        else:
            self.begin = element.next_element

        if element.next_element is not None:
            element.next_element.previous_element = element.previous_element

