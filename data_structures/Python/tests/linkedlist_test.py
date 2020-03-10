import unittest
from linkedlists import Node
from linkedlists import SimpleLinkedList


class TestNode(unittest.TestCase):
    def test_new_node_without_next(self):
        new_node = Node(1)
        self.assertEqual(new_node.key, 1)
        self.assertIsNone(new_node.next_element)

    def test_node_with_next(self):
        node_1 = Node(1)
        node_2 = Node(2, next_element=node_1)
        self.assertIs(node_2.next_element, node_1)


class TestLinkedListWhiteBox(unittest.TestCase):
    def setUp(self) -> None:
        self.linked_list = SimpleLinkedList()
        self.linked_list.insert(1)
        self.linked_list.insert(2)
        self.linked_list.insert(3)

    def test_init_empty(self):
        linked_list_empty = SimpleLinkedList()
        self.assertIsNone(linked_list_empty.begin)
        self.assertIsNone(linked_list_empty.end)

    def test_insert_one(self):
        linked_list_one = SimpleLinkedList()
        linked_list_one.insert(1)
        self.assertEqual(linked_list_one.begin.key, 1)
        self.assertEqual(linked_list_one.end.key, 1)

    def test_insert_two(self):
        linked_list_two = SimpleLinkedList()
        linked_list_two.insert(1)
        linked_list_two.insert(2)
        self.assertEqual(linked_list_two.begin.key, 2)
        self.assertEqual(linked_list_two.end.key, 1)

    def test_remove(self):
        self.linked_list.remove(2)
        self.assertFalse(self.linked_list.contains(2))
        self.assertTrue(self.linked_list.contains(1))
        self.assertTrue(self.linked_list.contains(3))

    def test_remove_last(self):
        self.assertEqual(self.linked_list.end.key, 1)
        self.linked_list.remove_last()
        self.assertFalse(self.linked_list.contains(1))
        self.assertTrue(self.linked_list.contains(2))
        self.assertTrue(self.linked_list.contains(3))
        self.assertEqual(self.linked_list.end.key, 2)

    def test_insert_last(self):
        self.assertEqual(self.linked_list.end.key, 1)
        self.linked_list.insert_last(4)
        self.assertEqual(self.linked_list.end.key, 4)


if __name__ == '__main__':
    unittest.main()
