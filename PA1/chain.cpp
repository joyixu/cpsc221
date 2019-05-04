#include "chain.h"
#include "chain_given.cpp"

// PA1 functions

/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
 */
Chain::~Chain(){
  clear();
  length_ = 0;
  cout << "12" << endl;
}

/**
 * Inserts a new node at the lastNode of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
void Chain::insertBack(const Block & ndata){
  cout << "22" << endl;
  	//construct a new node
  Node *newBlock = new Node(ndata);
   	//if the chain is empty
  if (size() == 0){
   	head_->next = newBlock;
    head_->prev = newBlock;
    newBlock->next = head_;
    newBlock->prev = head_;
		length_++;
    }
 
  else {
    Node *lastNode = head_->prev;
    lastNode->next = newBlock;
   	head_->prev = newBlock;
   	newBlock->next = head_;
    newBlock->prev = lastNode;
   	length_++;
  }
    cout << "39" << endl;
}


/**
 * Modifies the Chain by moving the subchain of len Nodes,
 * starting at position startPos, dist positions toward the
 * lastNode of the chain.  If startPos + len - 1 + dist > length
 * then dist = length - startPos - len + 1 (to prevent gaps
 * in the new chain).
 * The subchain occupies positions (startPos + dist) through
 * (startPos + dist + len - 1) of the resulting chain.
 * The order of subchain nodes is not changed in the move.
 * You may assume that: 1 <= startPos <= length - len + 1,
 * 0 <= dist <= length, and 0 <= len <= length. 
 */
void Chain::moveBack(int startPos, int len, int dist){
  /* your code here */
    cout << "54." << endl;
    if(startPos + len > length_ || length_ == 0 || dist == 0) {
      return;
    }
    if (startPos == 0) {
        startPos = 1;
        len--;
    }

    Node * before = walk(head_,startPos-1); // before startPos
    Node * first = walk(head_, startPos); // at startPos
    Node * end = walk(first,len-1); // last node of the subset

    //when there's not enough nodes, update new 
    while(walk(end,dist)->next==NULL){
        end=end->prev;
    }

    Node * after = walk(end,1); // node after last node of subset
    Node * newbefore = walk(end,dist);
    Node * newafter = walk(end,dist+1);
    
    before->next = after;
    after->prev = before;
    newbefore->next = first;
    first->prev = newbefore;
    end->next = newafter;
    newafter->prev = end;
}

/**
 * Rolls the current Chain by k nodes: reorders the current list
 * so that the curr k nodes are the (n-k+1)th, (n-k+2)th, ... , nth
 * nodes of the original list followed by the 1st, 2nd, ..., (n-k)th
 * nodes of the original list where n is the length.
 */
void Chain::roll(int k){
  /* your code here */
  cout << "95." << endl;
  if (k==0 || k > length_){
    return;
  }

  else {
    Node * subhead = walk(head_, length_-k+1);
    Node * subtail = walk(head_, length_);
    Node * front = walk(head_, 1);
    subhead->prev->next = head_->prev;
    head_->prev = subhead->prev;
    head_->next = subhead;
    subhead->prev = head_;
    front->prev = subtail;
    subtail->next= front;
  }
}

/**
 * Modifies the current chain by reversing the sequence
 * of nodes from pos1 up to and including pos2. You may
 * assume that pos1 and pos2 exist in the given chain,
 * and pos1 <= pos2.
 * The positions are 1-based.
 */
void Chain::reverseSub(int pos1, int pos2){
  /* your code here */
  cout << "123." << endl;
  if (pos1==pos2) {
    return;
    }

  Node*  front = walk(head_,pos1);
  Node*  before = front->prev;
  Node*  end = walk(head_,pos2);
  Node*  after = end-> next;
  Node* curr= end;
  Node* pcurr = before;
    
  front->next = after;
  after->prev=front;
  
  while ( curr!= before) {
     Node* temp = curr->prev;
     pcurr->next=curr;
     curr->prev=pcurr;
     pcurr=curr;
     curr=temp;
    }
}

/*
* Modifies both the current chain and the "other" chain by removing
* nodes from the other chain and adding them between the nodes
* of the current chain -- one "other" node between two current nodes --
* until one of the two chains is exhausted.  Then the rest of the
* nodes in the non-empty chain follow.
* The length of the resulting chain should be the sum of the lengths
* of current and other. The other chain should have only
* the head_ sentinel at the lastNode of the operation.
* The weave fails and the original
* chains should be unchanged if block sizes are different.
* In that case, the result of the function should be:
* cout << "Block sizes differ." << endl;
*/
void Chain::weave(Chain & other) { // leaves other empty.
  /* your code here */
  cout << "163." << endl;
  if ((height_ == other.height_ && width_ == other.width_) ||
   (height_ == other.width_ && width_ == other.height_)) {
    Node* node1 = head_->next;
    Node* node2 = other.head_->next;
      
    while(node1 != head_ && node2 != other.head_){
      Node* curr = node2;
      node2 = node2->next;
      curr->next->prev = curr->prev;
      curr->prev->next = curr->next;
      node1->next->prev = curr;
      curr->next = node1->next;
      node1->next = curr;
      curr->prev = node1;
      node1 = node1->next->next;
      length_++;
      other.length_--;
      }
  }

  else {
    cout << "Block sizes differ." << endl;
  }
}


/**
 * Destroys all dynamically allocated memory associated with the
 * current Chain class except for the sentinel head_. Sets length_
 * to zero.  After clear() the chain represents an empty chain.
 */
void Chain::clear() {
  cout << "199" << endl;
	while (head_->next != head_) {
		Node* temp = head_->next;
		temp->next->prev = head_;
		head_->next = temp->next;
		delete temp;
	}
	delete head_;
    cout << "211" << endl;
}


/**
 * Makes the current object into a copy of the parameter:
 * All member variables should have the same value as
 * those of other, but the memory should be completely
 * independent. This function is used in both the copy
 * constructor and the assignment operator for Chains.
 */
void Chain::copy(Chain const& other) {
  /* your code here */
  cout << "212" << endl;
  height_ = other.height_;
  width_ = other.width_;
  length_ = 0;
    
  head_ = new Node();
    
  Node *curr = other.head_->next;
  
  for (int i = 1; i <= other.length_; i++) {
     insertBack(curr->data);
      curr = curr->next;
  }
}
