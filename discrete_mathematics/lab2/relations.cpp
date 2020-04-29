#include <iostream>

using std::cout;

bool R1(int a, int b) {
  bool R = a > b;
  return R;
}

bool R2(int a, int b) {
  bool R = (b == a + 3);
  return R;
}

void display_matrix(int array[10][10]) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cout << array[i][j] << " ";
    }
    cout << "\n";
  }
}

void display_array(int count, int array[]) {
  cout << "{ ";
  for (int i = 0; i < count; i++)
    cout << array[i] << " ";
  cout << "}\n";
}

void create_relation_matrix(int array[10], int relation_matrix[10][10],
                            bool (*R)(int a, int b)) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      relation_matrix[i][j] = R(array[j], array[i]);
    }
  }
}

int find_definition_area(int relation_matrix[10][10], int *definition_area,
                         int A[10]) {
  int count = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (relation_matrix[i][j] == 1) {
        definition_area[count] = A[i];
        count++;
        i++;
        j = 0;
      }
    }
  }
  definition_area = (int *)realloc(definition_area, count * sizeof(int));
  return (count);
}

int find_set_of_values(int relation_matrix[10][10], int *set_of_values,
                       int A[10]) {
  int count = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (relation_matrix[i][j] == 1) {
        set_of_values[count] = A[j];
        count++;
        i++;
        j = 0;
      }
    }
  }
  set_of_values = (int *)realloc(set_of_values, count * sizeof(int));
  return (count);
}

void create_inverse_relation_matrix(int relation_matrix[10][10],
                                    int inverse_relation[10][10]) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      inverse_relation[j][i] = relation_matrix[i][j];
    }
  }
}

void find_addition(int relation_matrix[10][10],
                   int addition_for_relation[10][10]) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (relation_matrix[i][j] == 0)
        addition_for_relation[i][j] = 1;
      else
        addition_for_relation[i][j] = 0;
    }
  }
}

void build_transitive_lock(int relation_matrix[10][10],
                           int transitive_lock[10][10]) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      transitive_lock[i][j] = relation_matrix[i][j];
    }
  }
  for (int k = 0; k < 10; k++) {
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        transitive_lock[i][j] = transitive_lock[i][j] ||
                                transitive_lock[i][k] && transitive_lock[k][j];
      }
    }
  }
}

void find_composition(int relation_matrix1[10][10],
                      int relation_matrix2[10][10], int composition[10][10]) {
  int temp, a, b;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      for (int t = 0; t < 10; t++) {
        composition[i][j] += relation_matrix1[i][t] * relation_matrix2[t][j];
      }
    }
  }
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (composition[i][j]) {
        composition[i][j] = 1;
      }
    }
  }
}

void commutative_property(int result1[10][10], int result2[10][10]) {
  bool commutative = true;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (result1[i][j] != result2[i][j])
        commutative = false;
    }
  }
  if (commutative == true)
    cout << "composition procedure is commutative\n";
  else
    cout << "composition procedure is not commutative\n";
}

main() {
  int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int relation_matrix1[10][10] = {};
  int relation_matrix2[10][10] = {};
  cout << "\nrelation matrix for R1:\n";
  create_relation_matrix(A, relation_matrix1, R1);
  display_matrix(relation_matrix1);
  cout << "\nrelation matrix for R2:\n";
  create_relation_matrix(A, relation_matrix2, R2);
  display_matrix(relation_matrix2);
  int *definition_area1 = (int *)malloc(10 * sizeof(int));
  int *definition_area2 = (int *)malloc(10 * sizeof(int));
  int count;
  cout << "\ndefinition D area for R1:\n";
  count = find_definition_area(relation_matrix1, definition_area1, A);
  display_array(count, definition_area1);
  cout << "\ndefinition D area for R2:\n";
  count = find_definition_area(relation_matrix2, definition_area2, A);
  display_array(count, definition_area2);
  int *set_of_values1 = (int *)malloc(10 * sizeof(int));
  int *set_of_values2 = (int *)malloc(10 * sizeof(int));
  cout << "\nset of values E for R1:\n";
  count = find_set_of_values(relation_matrix1, set_of_values1, A);
  display_array(count, set_of_values1);
  cout << "\nset of values E area for R2:\n";
  count = find_set_of_values(relation_matrix2, set_of_values2, A);
  display_array(count, set_of_values2);
  int inverse_relation1[10][10] = {};
  int inverse_relation2[10][10] = {};
  cout << "\ninverse relation matrix for R1:\n";
  create_inverse_relation_matrix(relation_matrix1, inverse_relation1);
  display_matrix(inverse_relation1);
  cout << "\ninverse relation matrix for R2:\n";
  create_inverse_relation_matrix(relation_matrix2, inverse_relation2);
  display_matrix(inverse_relation2);
  int addition_for_relation1[10][10] = {};
  int addition_for_relation2[10][10] = {};
  cout << "\naddition for relation matrix for R1:\n";
  find_addition(relation_matrix1, addition_for_relation1);
  display_matrix(addition_for_relation1);
  cout << "\naddition for relation matrix for R2:\n";
  find_addition(relation_matrix2, addition_for_relation2);
  display_matrix(addition_for_relation2);
  int transitive_lock2[10][10] = {};
  cout << "\ntransitive lock for not transitive relation R2:\n";
  build_transitive_lock(relation_matrix2, transitive_lock2);
  display_matrix(transitive_lock2);
  int compositionR1_R2[10][10] = {};
  int compositionR2_R1[10][10] = {};
  cout << "\ncomposition for R1_R2:\n";
  find_composition(relation_matrix1, relation_matrix2, compositionR1_R2);
  display_matrix(compositionR1_R2);
  cout << "\ncomposition for R2_R1:\n";
  find_composition(relation_matrix2, relation_matrix1, compositionR2_R1);
  display_matrix(compositionR2_R1);
  commutative_property(compositionR1_R2, compositionR2_R1);
}
