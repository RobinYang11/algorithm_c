

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
    print('\n')
    if(tree.left != None):
      show_tree(tree.left)
    if(tree.right != None):
      show_tree(tree.right)

tree = start()

show_tree(tree)



