

from tkinter.messagebox import NO


PLUS = "+"
REDUCE = "-"
TIMES = "*"
DIVIDE = "/"

OPERATERS = {
    "*": 1,
    "/": 1,
    "+": 2,
    "-": 2
}


class Node:
    def __init__(self):
        self.value = ''
        self.left = None
        self.right = None


def start():
    exp = "1+2*3+4/5"
    tree = None
    for (index, item) in enumerate(exp):
        tree = Node()
        tree.value = item
        if tree != None:
          right_node= Node()
          right_node.value =item
          if(item.isdigit()):
            tree.right= right_node  
          else:
            right_node.left = tree
    return tree



def show_tree(tree):

  if(tree !=None):
    print(tree.value) 
    if(tree.left != None):
      show_tree(tree.left)
    if(tree.right != None):
      show_tree(tree.right)

tree = start()


my_tree =Node()

my_tree.value ="0"

n1= Node()
n1.value="1"
n2= Node()
n2.value="2"

n3= Node()
n3.value = "3"

n5 =Node()
n5.value="5"
n3.left =n5

n1.left=n3

n4= Node()
n4.value = "4"
n1.right= n4

my_tree.left= n1
my_tree.right=n2


show_tree(my_tree)



