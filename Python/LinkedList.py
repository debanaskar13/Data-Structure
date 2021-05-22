import gc
class node:
	def __init__(self,data):
		'''
			Initialize a Node
		'''
		self.data = data
		self.next = None

class LinkedList:
	def __init__(self):
		'''
			Initialize a Linked List
		'''
		self.head = None

	def insertAtFirst(self,data):
		'''
			insert a value after a specific value in a Linked List
		'''
		newnode = node(data)
		temp = self.head
		newnode.next = temp
		self.head = newnode

	def insertAfter(self,prevNode,data):
		'''
			insert value at first of the Linked List
		'''
		newnode = node(data)
		temp = self.head
		if temp == None:
			return
		if temp.data == prevNode:
			temp.next = newnode
			return

		while temp.data != prevNode:
			temp = temp.next
		newnode.next = temp.next
		temp.next = newnode

	def push(self,data):
		'''
			insert value at last of the Linked List
		'''
		newnode = node(data)
		if self.head==None:
			self.head = newnode
			return
		temp = self.head
		while temp.next!= None:
			temp = temp.next
		temp.next = newnode

	def deleteAtFirst(self):
		'''
			delate value at first of the Linked List
		'''		
		toDelete = self.head
		self.head = self.head.next
		del toDelete
		gc.collect()

	def pop(self):
		'''
			delete value at last of the Linked List
		'''
		temp = self.head
		if temp == None:
			return
		if temp.next == None:
			self.head = None
			return

		while temp.next.next!=None:
			temp = temp.next
		toDelete = temp.next
		temp.next = None
		del toDelete
		gc.collect()

	def delete(self,val):
		'''
			delete specific value from the Linked List
		'''
		temp = self.head
		if temp == None:
			return
		if self.head.data == val:
			toDelete = temp
			self.head = self.head.next
			del toDelete
			gc.collect()
			return
		while temp.next.data != val:
			temp = temp.next
		toDelete = temp.next
		temp.next = temp.next.next
		del toDelete
		gc.collect()

	def search(self,key):
		'''
		search a value in Linked List
		if value present in the Linked List then return 1 otherwise return 0
	    '''
		temp = self.head
		if temp == None:
			print(False)
			return
		while temp.next != None:
			if temp.data == key:
				print(True)
				return
			temp = temp.next
		print(False)

	def display(self):
		'''
		Display all value in Linked List
		'''
		temp = self.head
		while temp!=None:
			print(temp.data,end="->")
			temp = temp.next
		print('None')

	def reverse(self):
		temp = self.head
		prev = None
		curr = temp
		while curr != None:
			nextE = curr.next
			curr.next = prev
			prev = curr
			curr = nextE
		self.head = prev


if __name__ == '__main__':
	llist = LinkedList()
	llist.push(1)
	llist.push(2)
	llist.push(3)
	llist.push(4)
	llist.push(5)
	llist.display()
	llist.pop()
	llist.display()
	llist.deleteAtFirst()
	llist.display()
	llist.insertAtFirst(10)
	llist.display()
	llist.insertAfter(2,11)
	llist.display()
	llist.delete(3)
	llist.display()
	llist.search(21)
	llist.reverse()
	llist.display()