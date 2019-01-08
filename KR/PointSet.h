struct pnt{
	int x, y;
};

typedef struct pnt point;

struct dc{
	int pointCount;
	point list[100];
};

typedef struct dc PointSet;
