/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:32:21 by mhenin            #+#    #+#             */
/*   Updated: 2024/10/31 11:32:23 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// debut
// verification que cursor est a 0
// si cursor n'est pas a 0 alors on recupere se qu'il y a dans le buffer pour le mettre dans res jusqu'a un \n ou au \0 (la fonction qui fait ça modifie cursor pour le mettre a l'index du \n si il y en a un sinon il met cursor a 0)
// si cursor est pas a 0 apres ça on retourne res
// si cursor est a 0 on passe a la suite

// reading
// on lit dans le fd pour mettre dans buffer
// si rd_bytes est inferieur a 0 on retourne NULL et on free res si il est pas null
// si rd_bytes est a 0 on retourne null (⚠️ a verifier)
// on met un \0 a la fin du buffer soit buffer[rd_bytes] = '\0'
// on ajoute buffer a res, sachant que le join ne va add que j'usqu'au \n ou \0 mais si \n il va mettre cursor a l'index du \n
// donc si cursor est diff de 0 on sort de la boucle et on retourne res
