// initializing
struct idr id_huh;
idr_init(&id_huh);

// allocating is a two step process
// first resize the tree if necessary
int idr_pre_get(struct idr *idp, gfp_t gfp_mask);

// then obtain the actual UID
int idr_get_new(struct idr *idp, void *ptr, int *id);
// here the UID is stored in id and the value is *ptr

/*
 * Example
 */
int id;
do{
  if(!idr_pre_get(&id_huh, GFP_KERNEL))
    return -ENOSPC;
  ret = idr_get_new(&idr_huh, ptr, &id);
}while(ret == -EAGAIN);

// Looking up a UID
struct my_struct *ptr = idr_find(&idr_huh, id);
if(!ptr)
  return -EINVAL;

// removing a UID
void idr_remove(struct idr *idp, int id);
// no way to signify an error

// destroying idr
void idr_destroy(struct idr *idp);  // only destroys unused memory
void idr_destroy_all(struct idr *idp);  // destroy all memory
