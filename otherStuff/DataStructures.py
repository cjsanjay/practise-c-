class stack:
	
	def __init__(self):
		self.items=[]

	def push(self,item):
		self.items.append(item)

	def pop(self,item):
		return self.items.pop()

	def isEmpty(self):
		return self.items==[]

	def size(self):
		return len(self.items)
	
	def display(self):
		print self.items


obj= stack()

obj.push('test')
obj.push('champ')

obj.display()


