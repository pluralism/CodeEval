class Node
	attr_accessor :value, :left, :right, :root
	def initialize(value, root = nil)
		@value = value
		@left = nil
		@right = nil
		if root.nil?
			@root = self
		else
			@root = root
		end
	end
end


class Tree
	attr_accessor :nodes

	def initialize(nodes)
		@nodes = nodes
	end
	
	def find_node(val)
		@nodes.each do |node|
			return node if node.value == val
		end
		
		nil
	end
end

def calculate(root, a, b)
	left = nil
	right = nil
	
	return nil if root.nil?
	return root if root == a || root == b
	
	left = calculate(root.left, a, b)
	right = calculate(root.right, a, b)
	
	if left.nil? == false && right.nil? == false
		return root
	end
	
	if left.nil? == false
		left
	else
		right
	end
end


def lca(first, second)
	a = Node.new(30)
	b = Node.new(8, a)
	c = Node.new(52, a)
	d = Node.new(20, b)
	e = Node.new(3, b)
	f = Node.new(10, d)
	g = Node.new(29, d)
	a.left = b
	a.right = c
	b.left = e
	b.right = d
	d.left = f
	d.right = g
	nodes = [a, b, c, d, e, f, g]
	tree = Tree.new(nodes)
	first_node = tree.find_node(first)
	second_node = tree.find_node(second)
	return nil if first_node.nil? || second_node.nil?
	
	calculate(tree.nodes[0], first_node, second_node)
end


File.open(ARGV[0]).each do |line|
	arr = line.split
	puts lca(arr[0].to_i, arr[1].to_i).value
end
