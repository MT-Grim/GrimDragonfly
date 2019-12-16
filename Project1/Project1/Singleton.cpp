class Singleton {
	private:
		 Singleton(); // No c o n s t r u c t i n g .
		 Singleton(Singleton const &copy); // No c o p y i n g .
		 Singleton(Singleton const &assign); // No a s s i g n i n g .
	public:
		static Singleton & getInstance(); // Re turn i n s t a n c e .
	
};

// Re turn t h e one and o n l y i n s t a n c e o f t h e c l a s s .
Singleton & Singleton::getInstance() {
	 // Note , a s t a t i c v a r i a b l e p e r s i s t s a f t e r method en d s .
	 static Singleton single;
	return single;
}