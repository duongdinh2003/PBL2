void List::input_data_Car(const char* filename) {
	ifstream in;
	in.open(filename, ios::in);
	Node p;
	while (!in.eof()) {
		read_file_Car(p.p_history, in);
		Node* node = p.KhoitaoNode(p.p_history);
		addTail(node);
		size++;
	}
}
void List::output_data_Car(Purchase_history p_history) {
	p_history.output_car();
}
void List::display_Car() {
	Node* p;
	p = head;
	while (p != NULL) {
		output_data_Car(p->p_history);
		p = p->next;
	}
}
