import gc
class node:
	def __init__(self,data):
		self.data = data
		self.next = None

class LinkedList:
	def __init__(self):
		self.head = None

	def insertAtFirst(self,data):
		newnode = node(data)
		temp = self.head
		newnode.next = temp
		self.head = newnode

	def insertAfter(self,prevNode,data):
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
		newnode = node(data)
		if self.head==None:
			self.head = newnode
			return
		temp = self.head
		while temp.next!= None:
			temp = temp.next
		temp.next = newnode

	def deleteAtFirst(self):
		toDelete = self.head
		self.head = self.head.next
		del toDelete
		gc.collect()

	def pop(self):
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

	def deletion(self,val):
		pass

	def search(self,key):
		pass

	def display(self):
		temp = self.head
		while temp!=None:
			print(temp.data,end="->")
			temp = temp.next
		print('None')

	def reverse(self):
		pass

	def reverseRecursive(self):
		pass


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