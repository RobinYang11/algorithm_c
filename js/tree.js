function Node(value, parent, index) {
    this.value = value;
    this.parent = parent
    this.index = index;
}

function Tree() {
    this.nodes = []
    this.nodeNum = 0;
}

function insertNode(value, parent) {
    var node = new Node(value, parent, tree.nodeNum);
    this.nodes.push(node);
    this.nodeNum++;
}

function RDisplay(tree, node, gap) {
    var space = ""
    for (let i = 0; i < gap; i++) {
        space += "_"
    }
    console.log(space + node.value);
    for (let j = 0; j < tree.nodeNum; j++) {

        let g = gap + 1;
        if (tree.nodes[j].parent === node.index) {
            RDisplay(tree, tree.nodes[j], g);
        }
    }
}

function getTreeDepth() {
    console.log(this.nodes)
    let maxDepth = 0;

    this.nodes.forEach((i, index) => {
        let depth = 0;
        
        for (let s = index; s >= 0; s = this.nodes[i.parent].index) {
            depth++;
        }
        if (depth > maxDepth) {
            maxDepth = depth;
        }
    })
    return maxDepth;
}


function display() {
    RDisplay(this, this.nodes[0], 0);
}

Tree.prototype = {
    insertNode,
    display,
    getTreeDepth,
}

var tree = new Tree();

tree.insertNode("A", -1);
tree.insertNode("B", 0);
tree.insertNode("C", 0);
tree.insertNode("D", 0);
tree.insertNode("E", 1);
tree.insertNode("F", 1);
tree.insertNode("H", 1);
tree.insertNode("I", 2);
tree.insertNode("J", 2);

tree.display();
var depth =tree.getTreeDepth();
console.log(depth)
