#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
const long long maxs = 1e18;
struct node
{
    int type; //0 file, 1 dir;
    char *filename;
    long long LD = 1e18, LR = 1e18, NLD = 0, NLR = 0;
    vector<node *> file;
    vector<node *> dir;
    node(int _type = 0, char *_filename = NULL, long long _NLD = 0, long long _NLR = 0,
         long long _LD = 1e18, long long _LR = 1e18)
    {
        type = _type;
        filename = _filename;
        NLD = _NLD;
        NLR = _NLR;
        LD = _LD;
        LR = _LR;
    }
};
node *root = new node(1, "root");
void delete_tree(node *curnode)
{
    int dir_len = curnode->dir.size();
    for (int i = 0; i < dir_len; ++i)
    {
        delete_tree(curnode->dir[i]);
    }
    int file_len = curnode->file.size();
    for (int i = 0; i < file_len; ++i)
    {
        delete curnode->file[i];
        curnode->file[i] = NULL;
    }
    delete curnode;
}
bool cmp(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 != len2)
        return false;
    for (int i = 0; i < len1; ++i)
    {
        if (str1[i] != str2[i])
            return false;
    }
    return true;
}
node *is_exist(node *curnode, char *name)
{
    int dir_len = curnode->dir.size();
    for (int i = 0; i < dir_len; ++i)
    {
        if (cmp(curnode->dir[i]->filename, name))
            return curnode->dir[i];
    }
    int file_len = curnode->file.size();
    for (int i = 0; i < file_len; ++i)
    {
        if (cmp(curnode->file[i]->filename, name))
            return curnode->file[i];
    }
    return NULL;
}
bool create_file(char *filename, long long size)
{
    int len = strlen(filename);
    int i = 1;
    node *curnode = root;
    vector<node *> path;
    bool res = false;
    while (i < len)
    {
        char *name = new char[101];
        int j = 0;
        if (curnode->NLR + size > curnode->LR)
        {
            res = false;
            delete name;
            break;
        }
        while (i < len && filename[i] != '/')
        {
            name[j++] = filename[i++];
        }
        name[j] = '\0';
        path.push_back(curnode);
        node *exist = is_exist(curnode, name);
        if (i != len)
        {
            if (exist == NULL)
            {
                node *child = new node(1, name, 0, 0, maxs, maxs);
                // cout<<child->filename<<endl;
                curnode->dir.push_back(child);
                curnode = child;
            }
            else if (exist->type == 0)
            {
                res = false;
                delete name;
                break;
            }
            else if (exist->type == 1)
                curnode = exist;
        }
        else
        {
            if (exist == NULL || exist->type == 0)
            {
                if (curnode->NLD + size > curnode->LD)
                {
                    res = false;
                    break;
                }
            }
            if (exist == NULL)
            {
                node *child = new node(0, name, size, size, maxs, maxs);
                curnode->file.push_back(child);
                res = true;
                break;
            }
            else if (exist->type == 0)
            {
                // cout<<"get"<<endl;
                size = size - exist->NLR;
                exist->NLD += size;
                exist->NLR += size;
                res = true;
                break;
            }
            else if (exist->type == 1)
            {
                res = false;
                delete name;
                break;
            }
        }
        ++i;
        name = NULL;
    }

    int path_len = path.size();
    if (res)
    {
        for (int i = 0; i < path_len; ++i)
        {
            path[i]->NLR += size;
        }
        path[path_len - 1]->NLD += size;
    }
    return res;
}
bool remove_file(char *filename)
{
    int len = strlen(filename);
    int i = 1;
    node *curnode = root;
    node *delete_node = NULL;
    vector<node *> path;
    bool res = false;
    while (i < len)
    {
        char *name = new char[101];
        int j = 0;
        while (i < len && filename[i] != '/')
        {
            name[j++] = filename[i++];
        }
        name[j] = '\0';
        path.push_back(curnode);
        node *exist = is_exist(curnode, name);
        if (i != len)
        {
            if (exist == NULL || exist->type == 0)
            {
                res = false;
                break;
            }
            else
                curnode = exist;
        }
        else
        {
            if (exist == NULL)
            {
                res = false;
                break;
            }
            else
            {
                delete_node = exist;
                res = true;
            }
        }
        ++i;
        name = NULL;
    }
    if (res)
    {
        int path_len = path.size();
        for (int i = 0; i < path_len; ++i)
        {
            path[i]->NLR -= delete_node->NLR;
        }
        if (delete_node->type == 0)
        {
            path[path_len - 1]->NLD -= delete_node->NLD;
            curnode = path[path_len - 1];
            vector<node *>::iterator it = curnode->file.begin();
            for (; it != curnode->file.end();)
            {
                if (cmp((*it)->filename, delete_node->filename))
                {
                    it = curnode->file.erase(it);
                    break;
                }
                else
                    ++it;
            }
        }
        else if (delete_node->type == 1)
        {
            path[path_len - 1]->NLD -= delete_node->NLD;
            curnode = path[path_len - 1];
            vector<node *>::iterator it = curnode->file.begin();
            for (; it != curnode->file.end();)
            {
                if (cmp((*it)->filename, delete_node->filename))
                {
                    delete_tree(*it);
                    it = curnode->file.erase(it);
                    break;
                }
                else
                    ++it;
            }
        }
    }
    return true;
}
bool set_value(char *filename, long long LD, long long LR)
{
    if (LR == 0)
        LR = maxs;
    if (LD == 0)
        LD = maxs;
    int len = strlen(filename);
    int i = 1;
    node *curnode = root;
    node *delete_node = NULL;
    vector<node *> path;
    bool res = true;
    if (len == 1)
    {
        if (root->NLR > LR || root->NLD > LD)
            return false;
        else
        {
            root->LR = LR;
            root->LD = LD;
            return true;
        }
    }
    while (i < len)
    {
        char *name = new char[101];
        int j = 0;
        while (i < len && filename[i] != '/')
        {
            name[j++] = filename[i++];
        }
        name[j] = '\0';
        path.push_back(curnode);
        node *exist = is_exist(curnode, name);
        if (i != len)
        {
            if (exist == NULL || exist->type == 0)
            {
                res = false;
                delete name;
                break;
            }
            else
                curnode = exist;
        }
        else
        {
            if (exist == NULL || exist->type == 0)
            {
                res = false;
                delete name;
                break;
            }
            else
            {

                if (exist->NLR > LR || exist->NLD > LD)
                {
                    res = false;
                }
                else
                {
                    res = true;
                    exist->LR = LR;
                    exist->LD = LD;
                }
            }
        }
        ++i;
        delete name;
        name = NULL;
    }
    return res;
}
int n;
char res[100001];
int main()
{
    cin >> n;
    int j = 0;
    char type;
    long long size, LD, LR;
    for (int i = 0; i < n; ++i)
    {
        char path[101] = {'\0'};
        cin >> type >> path;
        if (type == 'C')
        {
            cin >> size;
            if (create_file(path, size))
                res[j++] = 'Y';
            else
                res[j++] = 'N';
        }
        else if (type == 'Q')
        {
            cin >> LD >> LR;
            if (set_value(path, LD, LR))
                res[j++] = 'Y';
            else
                res[j++] = 'N';
        }
        else
        {
            remove_file(path);
            res[j++] = 'Y';
        }
    }
    for (int i = 0; i < j; ++i)
    {
        printf("%c\n", res[i]);
    }
    system("pause");
    return 0;
}