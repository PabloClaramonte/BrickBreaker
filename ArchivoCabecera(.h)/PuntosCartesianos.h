class PuntosCartesianos
{

public: 

	//Son las tres variables sobre las cuales dependera todo el resto de los elementos, para poderlos situar en el mundo.
	float x, y, z;

	PuntosCartesianos(); // Declaracion del Constructor.
	~PuntosCartesianos(); //Declaracion del Destructor.

	//Getters (Se declaran en la cabecera para que sean Inline ya que se van a utilizar muchisimo).
	float ValorEspacial_x(void) { return x; }
	float ValorEspacial_y(void) {return y; }
	float ValorEspacial_z(void) { return z; }

	//Setters (Se delcaran en la cabecera para que sean Inline ya que se van a utilizar muchisimo).
	void DarValorEspacial_x(float valor) { x = valor; }
	void DarValorEspacial_y(float valor) { y = valor; }
	void DarValorEspacial_z(float valor) { z = valor; }

	//Incrementales y decrementales (Se delcaran en la cabecera para que sean Inline ya que se van a utilizar muchisimo).
	void IncrementoValorEspacial_x(float valor) { x = x + valor; }
	void IncrementoValorEspacial_y(float valor) { y = y + valor; }
	void IncrementoValorEspacial_z(float valor) { z = z + valor; }

};

